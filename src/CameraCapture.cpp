#include "CameraCapture.h"

CameraCapture::CameraCapture() {}

CameraCapture::~CameraCapture() {
    if (cap.isOpened()) {
        cap.release();
    }
}

bool CameraCapture::initialize(int deviceID) {
    cap.open(deviceID);
    return cap.isOpened();
}

cv::Mat CameraCapture::captureFrame() {
    cv::Mat frame;
    if (cap.isOpened()) {
        cap >> frame;
    }
    return frame;
}
