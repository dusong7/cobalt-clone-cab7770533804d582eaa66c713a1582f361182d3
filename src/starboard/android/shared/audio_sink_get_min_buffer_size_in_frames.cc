// Copyright 2019 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "starboard/audio_sink.h"

#include "starboard/android/shared/audio_track_audio_sink_type.h"
#include "starboard/common/log.h"

int SbAudioSinkGetMinBufferSizeInFrames(int channels,
                                        SbMediaAudioSampleType sample_type,
                                        int sampling_frequency_hz) {
  // Currently, we only use |min_required_frames_| for web audio, which
  // only supports 48k mono or stereo sound.
  SB_DCHECK(sampling_frequency_hz == 48000);

  if (channels <= 0 || channels > SbAudioSinkGetMaxChannels()) {
    SB_LOG(ERROR) << "Not support channels count " << channels;
    return -1;
  }
  if (sample_type != kSbMediaAudioSampleTypeInt16Deprecated &&
      sample_type != kSbMediaAudioSampleTypeFloat32) {
    SB_LOG(ERROR) << "Not support sample type " << sample_type;
    return -1;
  }
  if (sampling_frequency_hz <= 0) {
    SB_LOG(ERROR) << "Not support sample frequency " << sampling_frequency_hz;
    return -1;
  }

  return starboard::android::shared::AudioTrackAudioSinkType::
      GetMinBufferSizeInFrames(channels, sample_type, sampling_frequency_hz);
}
