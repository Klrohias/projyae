//
// Created by Twiiz on 2023/5/3.
//

#include "IAudioStream.h"

namespace ProjYae {
    ma_format IAudioStream::getSampleFormat() {
        return ma_format_unknown;
    }

    int IAudioStream::getChannelCount() {
        return 0;
    }

    uint64_t IAudioStream::getSampleCount() {
        return 0;
    }

    int IAudioStream::getSampleRate() {
        return 0;
    }

    void IAudioStream::read(ma_device *device, void *buffer, ma_uint32 frames) {

    }
} // ProjYae