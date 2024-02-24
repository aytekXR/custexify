#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H

#include <opencv2/opencv.hpp>

class CameraCapture {
public:
    CameraCapture();
    ~CameraCapture();
    bool initialize(int deviceID);
    cv::Mat captureFrame();

private:
    cv::VideoCapture cap;
};

#endif // CAMERACAPTURE_H
