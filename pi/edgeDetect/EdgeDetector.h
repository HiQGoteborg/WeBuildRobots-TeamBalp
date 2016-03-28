//
// Created by balp on 2016-02-28.
//

#ifndef IMAGEVIEW_EDGEDETECTOR_H
#define IMAGEVIEW_EDGEDETECTOR_H



#include <opencv2/opencv.hpp>

class EdgeDetector {
public:
    cv::Mat filter(cv::Mat);

    EdgeDetector() : factor(10.0), cutoffpoint(40) {}
private:
    double factor;
    int cutoffpoint;
};


#endif //IMAGEVIEW_EDGEDETECTOR_H
