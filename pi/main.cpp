//
//
//
#include <string>
#include <ctime>
#include <iostream>
#include <raspicam/raspicam_cv.h>
#include <opencv2/opencv.hpp>

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

#include "EdgeDetector.h"

using namespace std; 

int file_i2c;
const int arduino_address = 0x04;

void openi2c() {
    //----- OPEN THE I2C BUS -----
    char *filename = (char*)"/dev/i2c-1";
    if ((file_i2c = open(filename, O_RDWR)) < 0)
    {
        //ERROR HANDLING: you can check errno to see what went wrong
        cerr << "Failed to open the i2c bus" << endl;
        return;
    }

    int addr = arduino_address;          //<<<<<The I2C address of the slave
    if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
    {
        cerr << "Failed to acquire bus access and/or talk to slave." << endl;
        //ERROR HANDLING; you can check errno to see what went wrong
        return;
    }
}

void readi2c()
{
    unsigned char buffer[60] = {0};
    //----- READ BYTES -----
    const int length = 1;			//<<< Number of bytes to read
    if (read(file_i2c, buffer, length) != length)
    {
        //ERROR HANDLING: i2c transaction failed
        cerr << "Failed to read from the i2c bus." << endl;
    }
    else
    {
        cout << "Data read: " << (int) buffer[0] << endl;
    }
}

void writei2c() 
{
    unsigned char buffer[60] = {0};
    //----- WRITE BYTES -----
    buffer[0] = 0x01;
    buffer[1] = 0x02;
    const int length = 1;			//<<< Number of bytes to write
    if (write(file_i2c, buffer, length) != length)
    {
        /* ERROR HANDLING: i2c transaction failed */
        cerr << "Failed to write to the i2c bus." << endl;
    }
}
int main ( int argc,char **argv ) {
   
    openi2c();
    time_t timer_begin,timer_end;
    raspicam::RaspiCam_Cv Camera;
    cv::Mat image;
    cv::Mat filtered;
    EdgeDetector edgeDetector;
    int nCount=10;
    //set camera params
    Camera.set( CV_CAP_PROP_FRAME_WIDTH, 256 );
    Camera.set( CV_CAP_PROP_FRAME_HEIGHT, 256 );
    Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
    //Open camera
    cout<<"Opening Camera..."<<endl;
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}
    //Start capture
    cout<<"Capturing "<<nCount<<" frames ...."<<endl;
    time ( &timer_begin );
    for ( int i=0; i<nCount; i++ ) {
        Camera.grab();
        Camera.retrieve ( image);
        filtered = edgeDetector.filter(image);
        writei2c();
        readi2c();
        if ( i%5==0 )  cout<<"\r captured "<<i<<" images"<<std::flush;
    }
    cout<<"Stop camera..."<<endl;
    Camera.release();
    //show time statistics
    time ( &timer_end ); /* get current time; same as: timer = time(NULL)  */
    double secondsElapsed = difftime ( timer_end,timer_begin );
    cout<< secondsElapsed<<" seconds for "<< nCount<<"  frames : FPS = "<<  ( float ) ( ( float ) ( nCount ) /secondsElapsed ) <<endl;
    //save image 
    cv::imwrite("raspicam_cv_image.jpg",image);
    cv::imwrite("raspicam_cv_image_filtered.jpg",filtered);
    cout<<"Image saved at raspicam_cv_image.jpg"<<endl;
}
