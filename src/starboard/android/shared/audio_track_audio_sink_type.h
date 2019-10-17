// Copyright 2017 The Cobalt Authors. All Rights Reserved.
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

#ifndef STARBOARD_ANDROID_SHARED_AUDIO_TRACK_AUDIO_SINK_TYPE_H_
#define STARBOARD_ANDROID_SHARED_AUDIO_TRACK_AUDIO_SINK_TYPE_H_

#include <atomic>
#include <functional>

#include "starboard/android/shared/audio_sink_min_required_frames_tester.h"
#include "starboard/android/shared/jni_env_ext.h"
#include "starboard/android/shared/jni_utils.h"
#include "starboard/audio_sink.h"
#include "starboard/common/log.h"
#include "starboard/common/mutex.h"
#include "starboard/common/scoped_ptr.h"
#include "starboard/configuration.h"
#include "starboard/shared/internal_only.h"
#include "starboard/shared/starboard/audio_sink/audio_sink_internal.h"
#include "starboard/thread.h"

namespace starboard {
namespace android {
namespace shared {

class AudioTrackAudioSinkType : public SbAudioSinkPrivate::Type {
 public:
  static int GetMinBufferSizeInFrames(int channels,
                                      SbMediaAudioSampleType sample_type,
                                      int sampling_frequency_hz);

  AudioTrackAudioSinkType();

  SbAudioSink Create(
      int channels,
      int sampling_frequency_hz,
      SbMediaAudioSampleType audio_sample_type,
      SbMediaAudioFrameStorageType audio_frame_storage_type,
      SbAudioSinkFrameBuffers frame_buffers,
      int frames_per_channel,
      SbAudioSinkUpdateSourceStatusFunc update_source_status_func,
      SbAudioSinkConsumeFramesFunc consume_frames_func,
      void* context);

  bool IsValid(SbAudioSink audio_sink) override {
    return audio_sink != kSbAudioSinkInvalid && audio_sink->IsType(this);
  }

  void Destroy(SbAudioSink audio_sink) override {
    if (audio_sink != kSbAudioSinkInvalid && !IsValid(audio_sink)) {
      SB_LOG(WARNING) << "audio_sink is invalid.";
      return;
    }
    delete audio_sink;
  }

  void TestMinRequiredFrames();

 private:
  std::atomic_int min_required_frames_;
  MinRequiredFramesTester min_required_frames_tester_;
};

class AudioTrackAudioSink : public SbAudioSinkPrivate {
 public:
  AudioTrackAudioSink(
      Type* type,
      int channels,
      int sampling_frequency_hz,
      SbMediaAudioSampleType sample_type,
      SbAudioSinkFrameBuffers frame_buffers,
      int frames_per_channel,
      int preferred_buffer_size,
      SbAudioSinkUpdateSourceStatusFunc update_source_status_func,
      SbAudioSinkConsumeFramesFunc consume_frame_func,
      void* context);
  ~AudioTrackAudioSink() override;

  bool IsAudioTrackValid() const { return j_audio_track_bridge_; }
  bool IsType(Type* type) override { return type_ == type; }
  void SetPlaybackRate(double playback_rate) override;

  void SetVolume(double volume) override;
  int GetUnderrunCount();

 private:
  static void* ThreadEntryPoint(void* context);
  void AudioThreadFunc();

  int WriteData(JniEnvExt* env, const void* buffer, int size);

  Type* type_;
  int channels_;
  int sampling_frequency_hz_;
  SbMediaAudioSampleType sample_type_;
  void* frame_buffer_;
  int frames_per_channel_;
  SbAudioSinkUpdateSourceStatusFunc update_source_status_func_;
  SbAudioSinkConsumeFramesFunc consume_frame_func_;
  void* context_;
  int last_playback_head_position_;
  jobject j_audio_track_bridge_;
  jobject j_audio_data_;

  volatile bool quit_;
  SbThread audio_out_thread_;

  starboard::Mutex mutex_;
  double playback_rate_;

  int written_frames_;
};

}  // namespace shared
}  // namespace android
}  // namespace starboard

#endif  // STARBOARD_ANDROID_SHARED_AUDIO_TRACK_AUDIO_SINK_TYPE_H_
