/***********************************************************************
 * Exp2_DriveForward -- RedBot Experiment 2
 * 
 * Drive forward and stop.
 * 
 * Hardware setup:
 * The Power switch must be on, the motors must be connected, and the board must be receiving power 
 * from the battery. The motor switch must also be switched to RUN.
 *
 * 23 Sept 2013 N. Seidle/M. Hord
 * 04 Oct 2014 B. Huang
 ***********************************************************************/
#include <Wire.h>
#include <RedBot.h>  // This line "includes" the RedBot library into your sketch.
// Provides special objects, methods, and functions for the RedBot.

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

RedBotMotors motors; // Instantiate the motor control object. This only needs
// to be done once.

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600); 
  Wire.begin(SLAVE_ADDRESS);
  motors.drive(255);   // Turn on Left and right motors at full speed forward.
  delay(2000);         // Waits for 2 seconds
  motors.stop();       // Stops both motors
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("Ready!");
}

void loop()
{
  // Nothing here. We'll get to this in the next experiment.
  delay(100);
}

void receiveData(int byteCount){
  
  while(Wire.available()) {
    number = Wire.read();
    Serial.print("data recived");
    Serial.println(number);
    
    if (number == 1){
      if (state == 0){
        digitalWrite(13, HIGH); // set the LED on
        state = 1;
      }
      else{
        digitalWrite(13, LOW); // set the LED off
        state = 0;
      }
    }
  }
}

void sendData(){
  Wire.write(number);
}


