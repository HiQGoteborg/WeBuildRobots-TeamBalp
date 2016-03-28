//
// Created by balp on 2016-02-28.
//

#include <opencv2/opencv.hpp>
#include "EdgeDetector.h"
#include <iostream>

using namespace cv;

cv::Mat EdgeDetector::filter(cv::Mat mat) {
    filter2D(mat, edgeDetected, mat.depth(), edgeDetectionMatrix);

    Mat floatMatrix;
    edgeDetected.convertTo(floatMatrix, CV_32F);
    Mat pow2;
    pow(floatMatrix, factor, pow2);

    Mat normalized;
    normalize(pow2, normalized, 0, 255, NORM_MINMAX);
    Mat thresholded;
    threshold(normalized, thresholded, cutoffpoint, 255, THRESH_BINARY);

    return thresholded;
}
