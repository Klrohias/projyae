//
// Created by Twiiz on 2023/5/3.
//

#ifndef PROJYAE_FLACAUDIOSTREAM_H
#define PROJYAE_FLACAUDIOSTREAM_H

#include "IAudioStream.h"
#include "drlibs.h"
#include <string>

namespace ProjYae
{

    class FlacAudioStream : public IAudioStream
    {
        drflac* _decoder = nullptr;

        friend void flac_on_metadata(void* flacAudioStream, drflac_metadata* metadata);

    public:
        explicit FlacAudioStream(std::string path);

        ~FlacAudioStream();

        ma_format getSampleFormat() override;

        int getChannelCount() override;

        uint64_t getSampleCount() override;

        int getSampleRate() override;

        void read(ma_device* device, void* buffer, ma_uint32 frames) override;

    };

} // ProjYae

#endif //PROJYAE_FLACAUDIOSTREAM_H
