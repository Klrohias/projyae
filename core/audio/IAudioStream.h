//
// Created by Twiiz on 2023/5/3.
//

#ifndef PROJYAE_IAUDIOSTREAM_H
#define PROJYAE_IAUDIOSTREAM_H

#include "miniaudio.h"

namespace ProjYae {

    class IAudioStream {
    public:
        virtual ma_format getSampleFormat();
        virtual int getChannelCount();
        virtual long getSampleCount();
        virtual int getSampleRate();
        virtual void read(ma_device* device, void* buffer, ma_uint32 frames);
    };

} // ProjYae

#endif //PROJYAE_IAUDIOSTREAM_H
