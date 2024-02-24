#ifndef MICROPHONECAPTURE_H
#define MICROPHONECAPTURE_H

#include <portaudio.h>

class MicrophoneCapture {
public:
    MicrophoneCapture();
    ~MicrophoneCapture();
    bool initialize();
    void startCapture();
    void stopCapture();

private:
    static int recordCallback(const void *inputBuffer, void *outputBuffer,
                              unsigned long framesPerBuffer,
                              const PaStreamCallbackTimeInfo* timeInfo,
                              PaStreamCallbackFlags statusFlags,
                              void *userData);
    PaStream *stream;
};

#endif // MICROPHONECAPTURE_H
