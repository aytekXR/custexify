#include "CameraCapture.h"
#include "MicrophoneCapture.h"
#include "SpeakerOutput.h"
#include <opencv2/highgui.hpp> // For displaying the captured frame

int main() {
    // Initialize Camera
    CameraCapture camera;
    if (!camera.initialize(0)) { // Try to open the default camera
        std::cerr << "Failed to open camera." << std::endl;
        return -1;
    }

    // Initialize Microphone
    MicrophoneCapture microphone;
    if (!microphone.initialize()) {
        std::cerr << "Failed to initialize microphone." << std::endl;
        return -1;
    }

    // Initialize Speaker
    SpeakerOutput speaker;
    if (!speaker.initialize()) {
        std::cerr << "Failed to initialize speaker." << std::endl;
        return -1;
    }

    // Start audio capture (this is just a placeholder, adapt as necessary for your application)
    microphone.startCapture();

    // Main loop
    while (true) {
        cv::Mat frame = camera.captureFrame();
        if (frame.empty()) {
            std::cerr << "Failed to capture frame." << std::endl;
            break;
        }

        // Display the captured frame
        cv::imshow("Frame", frame);

        // Placeholder for playing sound (adapt as necessary)
        // speaker.playSound(buffer, size);

        // Break the loop when user presses a key
        if (cv::waitKey(30) >= 0) break;
    }

    // Clean up
    microphone.stopCapture();

    return 0;
}
