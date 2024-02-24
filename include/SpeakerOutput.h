#ifndef SPEAKEROUTPUT_H
#define SPEAKEROUTPUT_H

#include <alsa/asoundlib.h>

class SpeakerOutput {
public:
    SpeakerOutput();
    ~SpeakerOutput();
    bool initialize();
    void playSound(const void* buffer, size_t size);

private:
    snd_pcm_t *handle;
};

#endif // SPEAKEROUTPUT_H
