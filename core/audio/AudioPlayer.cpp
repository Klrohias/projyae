//
// Created by Twiiz on 2023/5/3.
//

#include "AudioPlayer.h"
#include "miniaudio.h"
#include <memory>
#include "../utilities.h"

namespace ProjYae {
    void miniaudio_pcm_callback_wrapper(ma_device *device, void *buffer, const void *unused, ma_uint32 count) {
        __UNUSED_PTR(unused);

        auto *player = reinterpret_cast<AudioPlayer *>(device->pUserData);
        auto *stream = player->_stream;


        if (!player->_playing) {
            // pause
            auto bufferLength = stream->getChannelCount() * count;
            switch (stream->getSampleFormat()) {
                case ma_format_u8:
                    memset(buffer, 0, sizeof(uint8_t) * bufferLength);
                    break;
                case ma_format_s16:
                    memset(buffer, 0, sizeof(int16_t) * bufferLength);
                    break;
                case ma_format_s24:
                    memset(buffer, 0, 3 * bufferLength);
                    break;
                case ma_format_s32:
                case ma_format_f32:
                    memset(buffer, 0, sizeof(int32_t) * bufferLength);
                    break;
                default:
                    break;
            }
            return;
        }
        stream->read(device, buffer, count);
    }

    void AudioPlayer::play(IAudioStream *audioStream) {
        if (!audioStream) {
            return;
        }

        _stream = audioStream;
        _deviceConfig.playback.format = audioStream->getSampleFormat();
        _deviceConfig.playback.channels = audioStream->getChannelCount();
        _deviceConfig.sampleRate = audioStream->getSampleRate();
        _deviceConfig.pUserData = this;

        // create
        release_device();
        _device = static_cast<ma_device *>(malloc(sizeof(ma_device)));
        if (ma_device_init(nullptr, &_deviceConfig, _device) != MA_SUCCESS) {
            return;
        }
        _playing = true;
    }

    AudioPlayer::AudioPlayer() {
        _deviceConfig = ma_device_config_init(ma_device_type_playback);
        _deviceConfig.dataCallback = miniaudio_pcm_callback_wrapper;
    }

    AudioPlayer::~AudioPlayer() {
        release_device();
    }

    void AudioPlayer::release_device() {
        if (_device) {
            ma_device_uninit(_device);
            free(_device);
            _device = nullptr;
        }
    }

    void AudioPlayer::pause() {
        _playing = false;
    }

    void AudioPlayer::resume() {
        _playing = false;
    }

    void AudioPlayer::stop() {
        _playing = false;
        ma_device_stop(_device);
    }

} // ProjYae