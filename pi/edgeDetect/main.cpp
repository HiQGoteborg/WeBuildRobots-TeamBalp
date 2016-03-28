//
// Created by balp on 2016-02-28.
//
#include <string>
#include <opencv2/opencv.hpp>

#include "EdgeDetector.h"

using namespace cv;

int main(int argc, char **argv) {
    std::string imageName = "startImages/straight.jpg";
    if (argc == 2) {
        imageName = argv[1];
    }
    EdgeDetector edgeDetector;
    Mat image = edgeDetector.filter(imread(imageName, IMREAD_GRAYSCALE));

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);

    return 0;
}
