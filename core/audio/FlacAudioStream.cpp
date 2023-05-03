//
// Created by Twiiz on 2023/5/3.
//

#include "FlacAudioStream.h"

namespace ProjYae
{
    /*void flac_on_metadata(void* flacAudioStream, drflac_metadata* metadata) {
        if(metadata->type != DRFLAC_METADATA_BLOCK_TYPE_CUESHEET) {
            return;
        }

        drflac_cuesheet_track_iterator i;
        drflac_cuesheet_track track;

        printf("Cuesheet Found. Track Count = %d\n", (int)metadata->data.cuesheet.trackCount);

        drflac_init_cuesheet_track_iterator(&i, pMetadata->data.cuesheet.trackCount, pMetadata->data.cuesheet.pTrackData);
        while (drflac_next_cuesheet_track(&i, &track)) {
            drflac_uint32 iTrackIndex;

            printf("Cuesheet Track %d. Index Count = %d:\n", track.trackNumber, track.indexCount);
            for (iTrackIndex = 0; iTrackIndex < track.indexCount; iTrackIndex += 1) {
                printf("    Index %d - Offset %llu\n", iTrackIndex, track.pIndexPoints[iTrackIndex].offset);
            }
        }

    }*/


    FlacAudioStream::FlacAudioStream(std::string path)
    {
        _decoder = drflac_open_file(path.c_str(), nullptr);
    }

    FlacAudioStream::~FlacAudioStream()
    {
        if (_decoder)
        {
            drflac_close(_decoder);
        }
    }

    ma_format FlacAudioStream::getSampleFormat()
    {
        return ma_format_s16;
    }

    int FlacAudioStream::getChannelCount()
    {
        return _decoder->channels;
    }

    uint64_t FlacAudioStream::getSampleCount()
    {
        return _decoder->totalPCMFrameCount;
    }

    int FlacAudioStream::getSampleRate()
    {
        return static_cast<int>(_decoder->sampleRate);
    }

    void FlacAudioStream::read(ma_device* device, void* buffer, ma_uint32 frames)
    {
        drflac_read_pcm_frames_s16(_decoder, frames, reinterpret_cast<drwav_int16 *>(buffer));
    }
} // ProjYae