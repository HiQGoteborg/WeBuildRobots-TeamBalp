//
// Created by balp on 2016-02-28.
//

#ifndef IMAGEVIEW_EDGEDETECTOR_H
#define IMAGEVIEW_EDGEDETECTOR_H



#include <opencv2/opencv.hpp>

class EdgeDetector {
public:
    cv::Mat filter(cv::Mat);

    EdgeDetector() : factor(10.0), cutoffpoint(40) {
        edgeDetectionMatrix = (cv::Mat_<char>(5, 5) <<
                               -1, -1, -1, -1, -1,
            -1,  0,  0,  0, -1,
            -1,  0, 16,  0, -1,
            -1,  0,  0,  0, -1,
            -1, -1, -1, -1, -1
            );
    }
private:
    double factor;
    int cutoffpoint;
    cv::Mat edgeDetected;
    cv::Mat edgeDetectionMatrix;
};


#endif //IMAGEVIEW_EDGEDETECTOR_H
