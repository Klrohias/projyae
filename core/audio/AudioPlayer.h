//
// Created by Twiiz on 2023/5/3.
//

#ifndef PROJYAE_AUDIOPLAYER_H
#define PROJYAE_AUDIOPLAYER_H

#include "IAudioStream.h"
#include "miniaudio.h"

namespace ProjYae {

    class AudioPlayer {
        ma_device_config _deviceConfig{};
        ma_device *_device = nullptr;
        IAudioStream *_stream = nullptr;
        bool _playing = false;

        friend void
        miniaudio_pcm_callback_wrapper(ma_device *device, void *buffer, const void *unused, ma_uint32 count);

    public:
        explicit AudioPlayer();

        ~AudioPlayer();

        void play(IAudioStream *audioStream);

        void pause();

        void resume();

        void stop();

    private:
        void release_device();
    };

} // ProjYae

#endif //PROJYAE_AUDIOPLAYER_H
