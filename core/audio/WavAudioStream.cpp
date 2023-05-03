//
// Created by Twiiz on 2023/5/3.
//

#include "WavAudioStream.h"

namespace ProjYae {
    WavAudioStream::WavAudioStream(std::string path) {
        _decoder = static_cast<drwav *>(malloc(sizeof(drwav)));
        if (!drwav_init_file_with_metadata(_decoder, path.c_str(), 0, nullptr)) {
            return;
        }
    }

    WavAudioStream::~WavAudioStream() {
        if (_decoder) {
            drwav_uninit(_decoder);
            free(_decoder);
        }
    }

    ma_format WavAudioStream::getSampleFormat() {
        return ma_format_s16;
    }

    int WavAudioStream::getChannelCount() {
        return _decoder->channels;
    }

    uint64_t WavAudioStream::getSampleCount() {
        return _decoder->totalPCMFrameCount;
    }

    int WavAudioStream::getSampleRate() {
        return _decoder->sampleRate;
    }

    void WavAudioStream::read(ma_device *device, void *buffer, ma_uint32 frames) {
        drwav_read_pcm_frames_s16(_decoder, frames, reinterpret_cast<drwav_int16 *>(buffer));
    }

} // ProjYae