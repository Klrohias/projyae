//
// Created by Twiiz on 2023/5/3.
//

#ifndef PROJYAE_MP3AUDIOSTREAM_H
#define PROJYAE_MP3AUDIOSTREAM_H

#include "IAudioStream.h"
#include "drlibs.h"
#include <string>

namespace ProjYae
{

    class Mp3AudioStream : public IAudioStream
    {
        drmp3* _decoder = nullptr;
    public:
        explicit Mp3AudioStream(std::string path);

        ~Mp3AudioStream();

        ma_format getSampleFormat() override;

        int getChannelCount() override;

        uint64_t getSampleCount() override;

        int getSampleRate() override;

        void read(ma_device* device, void* buffer, ma_uint32 frames) override;

    };

} // ProjYae

#endif //PROJYAE_MP3AUDIOSTREAM_H
