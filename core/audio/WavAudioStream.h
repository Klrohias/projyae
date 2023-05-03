//
// Created by Twiiz on 2023/5/3.
//

#ifndef PROJYAE_WAVAUDIOSTREAM_H
#define PROJYAE_WAVAUDIOSTREAM_H

#include "IAudioStream.h"
#include "drlibs.h"
#include <string>

namespace ProjYae {

    class WavAudioStream : public IAudioStream {
        drwav *_decoder = nullptr;
    public:
        explicit WavAudioStream(std::string path);

        ~WavAudioStream();

        ma_format getSampleFormat() override;

        int getChannelCount() override;

        uint64_t getSampleCount() override;

        int getSampleRate() override;

        void read(ma_device *device, void *buffer, ma_uint32 frames) override;
    };

} // ProjYae

#endif //PROJYAE_WAVAUDIOSTREAM_H
