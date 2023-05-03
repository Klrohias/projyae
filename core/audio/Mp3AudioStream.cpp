//
// Created by Twiiz on 2023/5/3.
//

#include "Mp3AudioStream.h"

namespace ProjYae
{
    Mp3AudioStream::Mp3AudioStream(std::string path)
    {
        _decoder = static_cast<drmp3*>(malloc(sizeof(drmp3)));
        if (!drmp3_init_file(_decoder, path.c_str(), nullptr))
        {
            return;
        }
    }

    Mp3AudioStream::~Mp3AudioStream()
    {
        if (_decoder)
        {
            drmp3_uninit(_decoder);
            free(_decoder);
        }
    }

    ma_format Mp3AudioStream::getSampleFormat()
    {
        return ma_format_s16;
    }

    int Mp3AudioStream::getChannelCount()
    {
        return static_cast<int>(_decoder->channels);
    }

    uint64_t Mp3AudioStream::getSampleCount()
    {
        return drmp3_get_pcm_frame_count(_decoder) * _decoder->channels;
    }

    int Mp3AudioStream::getSampleRate()
    {
        return _decoder->sampleRate;
    }

    void Mp3AudioStream::read(ma_device* device, void* buffer, ma_uint32 frames)
    {
        drmp3_read_pcm_frames_s16(_decoder, frames, static_cast<drmp3_int16*>(buffer));
    }


} // ProjYae