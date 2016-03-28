//
// Created by balp on 2016-02-28.
//

#include <opencv2/opencv.hpp>
#include "EdgeDetector.h"
#include <iostream>

using namespace cv;

cv::Mat EdgeDetector::filter(cv::Mat mat) {
    Mat edgeDetectionMatrix = (Mat_<char>(5, 5) <<
                               -1, -1, -1, -1, -1,
            -1,  0,  0,  0, -1,
            -1,  0, 16,  0, -1,
            -1,  0,  0,  0, -1,
            -1, -1, -1, -1, -1
            );
    std::cout << mat.type() << std::endl;
    Mat edgeDetected;
    filter2D(mat, edgeDetected, mat.depth(), edgeDetectionMatrix);
    Mat floatMatrix;
    edgeDetected.convertTo(floatMatrix, CV_32F);
    Mat pow2;
    
    pow(floatMatrix, factor, pow2);
    //std::cout << pow2 << std::endl;
    Mat normalized;
    normalize(pow2, normalized, 0, 255, NORM_MINMAX);
    //std::cout << normalized << std::endl;
    Mat thresholded;
    threshold(normalized, thresholded, cutoffpoint, 255, THRESH_BINARY);
    return thresholded;
}
