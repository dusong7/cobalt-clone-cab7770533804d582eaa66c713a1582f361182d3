// Copyright 2018 The Cobalt Authors. All Rights Reserved.
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

#include "starboard/shared/starboard/player/video_dmp_common.h"

#include <limits>

#if SB_HAS(PLAYER_FILTER_TESTS)
namespace starboard {
namespace shared {
namespace starboard {
namespace player {
namespace video_dmp {

#define DEFINE_READ_AS_INT32_FUNCTION(Type)                                \
  void Read(const ReadCB& read_cb, bool reverse_byte_order, Type* value) { \
    SB_DCHECK(value);                                                      \
    int32_t int32_value;                                                   \
    Read(read_cb, &int32_value, sizeof(int32_value));                      \
    if (reverse_byte_order) {                                              \
      std::reverse(reinterpret_cast<uint8_t*>(&int32_value),               \
                   reinterpret_cast<uint8_t*>(&int32_value + 1));          \
    }                                                                      \
    *value = static_cast<Type>(int32_value);                               \
  }

#define DEFINE_READ_AS_UINT32_FUNCTION(Type)                               \
  void Read(const ReadCB& read_cb, bool reverse_byte_order, Type* value) { \
    SB_DCHECK(value);                                                      \
    uint32_t uint32_value;                                                 \
    Read(read_cb, &uint32_value, sizeof(uint32_value));                    \
    if (reverse_byte_order) {                                              \
      std::reverse(reinterpret_cast<uint8_t*>(&uint32_value),              \
                   reinterpret_cast<uint8_t*>(&uint32_value + 1));         \
    }                                                                      \
    *value = static_cast<Type>(uint32_value);                              \
  }

#define DEFINE_WRITE_AS_INT32_FUNCTION(Type)            \
  void Write(const WriteCB& write_cb, Type value) {     \
    int32_t int32_value = static_cast<int32_t>(value);  \
    Write(write_cb, &int32_value, sizeof(int32_value)); \
  }

#define DEFINE_WRITE_AS_UINT32_FUNCTION(Type)             \
  void Write(const WriteCB& write_cb, Type value) {       \
    int32_t uint32_value = static_cast<uint32_t>(value);  \
    Write(write_cb, &uint32_value, sizeof(uint32_value)); \
  }

DEFINE_READ_AS_INT32_FUNCTION(bool)
DEFINE_WRITE_AS_INT32_FUNCTION(bool)

DEFINE_READ_AS_INT32_FUNCTION(int)
DEFINE_WRITE_AS_INT32_FUNCTION(int)

DEFINE_READ_AS_UINT32_FUNCTION(unsigned int)
DEFINE_WRITE_AS_UINT32_FUNCTION(unsigned int)

DEFINE_WRITE_AS_UINT32_FUNCTION(RecordType)

void Read(const ReadCB& read_cb, void* buffer, size_t size) {
  if (size == 0) {
    return;
  }
  int bytes_to_read = static_cast<int>(size);
  int bytes_read = read_cb(buffer, bytes_to_read);
  SB_DCHECK(bytes_read == bytes_to_read);
}

void Write(const WriteCB& write_cb, const void* buffer, size_t size) {
  if (size == 0) {
    return;
  }
  int bytes_to_write = static_cast<int>(size);
  int bytes_written = write_cb(buffer, bytes_to_write);
  SB_DCHECK(bytes_written == bytes_to_write);
}

void Read(const ReadCB& read_cb,
          bool reverse_byte_order,
          SbMediaAudioSampleInfoWithConfig* audio_sample_info) {
#if SB_API_VERSION >= 11
  Read(read_cb, reverse_byte_order, &audio_sample_info->codec);
#else   // SB_API_VERSION >= 11
  SbMediaAudioCodec codec;
  Read(read_cb, reverse_byte_order, &codec);
#endif  // SB_API_VERSION >= 11
  Read(read_cb, reverse_byte_order, &audio_sample_info->format_tag);
  Read(read_cb, reverse_byte_order, &audio_sample_info->number_of_channels);
  Read(read_cb, reverse_byte_order, &audio_sample_info->samples_per_second);
  Read(read_cb, reverse_byte_order,
       &audio_sample_info->average_bytes_per_second);
  Read(read_cb, reverse_byte_order, &audio_sample_info->block_alignment);
  Read(read_cb, reverse_byte_order, &audio_sample_info->bits_per_sample);
  Read(read_cb, reverse_byte_order,
       &audio_sample_info->audio_specific_config_size);
  audio_sample_info->stored_audio_specific_config.resize(
      audio_sample_info->audio_specific_config_size);
  audio_sample_info->audio_specific_config =
      audio_sample_info->stored_audio_specific_config.data();
  Read(read_cb, audio_sample_info->stored_audio_specific_config.data(),
       audio_sample_info->audio_specific_config_size);
}

void Write(const WriteCB& write_cb,
           SbMediaAudioCodec audio_codec,
           const SbMediaAudioSampleInfo& audio_sample_info) {
  Write(write_cb, audio_codec);
  Write(write_cb, audio_sample_info.format_tag);
  Write(write_cb, audio_sample_info.number_of_channels);
  Write(write_cb, audio_sample_info.samples_per_second);
  Write(write_cb, audio_sample_info.average_bytes_per_second);
  Write(write_cb, audio_sample_info.block_alignment);
  Write(write_cb, audio_sample_info.bits_per_sample);
  Write(write_cb, audio_sample_info.audio_specific_config_size);
  Write(write_cb, audio_sample_info.audio_specific_config,
        audio_sample_info.audio_specific_config_size);
}

void Read(const ReadCB& read_cb,
          bool reverse_byte_order,
          SbDrmSampleInfoWithSubSampleMapping* drm_sample_info) {
  SB_DCHECK(drm_sample_info);

  Read(read_cb, reverse_byte_order,
       &drm_sample_info->initialization_vector_size);
  Read(read_cb, drm_sample_info->initialization_vector,
       drm_sample_info->initialization_vector_size);
  Read(read_cb, reverse_byte_order, &drm_sample_info->identifier_size);
  Read(read_cb, drm_sample_info->identifier, drm_sample_info->identifier_size);
  Read(read_cb, reverse_byte_order, &drm_sample_info->subsample_count);
  drm_sample_info->stored_subsample_mapping.resize(
      static_cast<size_t>(drm_sample_info->subsample_count));
  drm_sample_info->subsample_mapping =
      drm_sample_info->stored_subsample_mapping.data();
  for (int i = 0; i < drm_sample_info->subsample_count; ++i) {
    Read(read_cb, reverse_byte_order,
         &(drm_sample_info->stored_subsample_mapping[i].clear_byte_count));
    Read(read_cb, reverse_byte_order,
         &(drm_sample_info->stored_subsample_mapping[i].encrypted_byte_count));
  }
}

void Write(const WriteCB& write_cb, const SbDrmSampleInfo& drm_sample_info) {
  Write(write_cb, drm_sample_info.initialization_vector_size);
  Write(write_cb, drm_sample_info.initialization_vector,
        drm_sample_info.initialization_vector_size);
  Write(write_cb, drm_sample_info.identifier_size);
  Write(write_cb, drm_sample_info.identifier, drm_sample_info.identifier_size);
  Write(write_cb, drm_sample_info.subsample_count);
  for (int i = 0; i < drm_sample_info.subsample_count; ++i) {
    Write(write_cb, drm_sample_info.subsample_mapping[i].clear_byte_count);
    Write(write_cb, drm_sample_info.subsample_mapping[i].encrypted_byte_count);
  }
}

void Read(const ReadCB& read_cb,
          bool reverse_byte_order,
          SbMediaVideoSampleInfoWithOptionalColorMetadata* video_sample_info) {
#if SB_API_VERSION >= 11
  Read(read_cb, reverse_byte_order, &video_sample_info->codec);
#else   // SB_API_VERSION >= 11
  SbMediaVideoCodec codec;
  Read(read_cb, reverse_byte_order, &codec);
#endif  // SB_API_VERSION >= 11
  Read(read_cb, reverse_byte_order, &video_sample_info->is_key_frame);
  Read(read_cb, reverse_byte_order, &video_sample_info->frame_width);
  Read(read_cb, reverse_byte_order, &video_sample_info->frame_height);

#if SB_API_VERSION >= 11
  auto& color_metadata = video_sample_info->color_metadata;
#else   // SB_API_VERSION >= 11
  video_sample_info->color_metadata = &video_sample_info->stored_color_metadata;
  auto& color_metadata = *video_sample_info->color_metadata;
#endif  // SB_API_VERSION >= 11

  Read(read_cb, reverse_byte_order, &color_metadata.bits_per_channel);
  Read(read_cb, reverse_byte_order,
       &color_metadata.chroma_subsampling_horizontal);
  Read(read_cb, reverse_byte_order,
       &color_metadata.chroma_subsampling_vertical);
  Read(read_cb, reverse_byte_order, &color_metadata.cb_subsampling_horizontal);
  Read(read_cb, reverse_byte_order, &color_metadata.cb_subsampling_vertical);
  Read(read_cb, reverse_byte_order, &color_metadata.chroma_siting_horizontal);
  Read(read_cb, reverse_byte_order, &color_metadata.chroma_siting_vertical);

  auto& mastering_metadata = color_metadata.mastering_metadata;
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.primary_r_chromaticity_x);
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.primary_r_chromaticity_y);
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.primary_g_chromaticity_x);
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.primary_g_chromaticity_y);
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.primary_b_chromaticity_x);
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.primary_b_chromaticity_y);
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.white_point_chromaticity_x);
  Read(read_cb, reverse_byte_order,
       &mastering_metadata.white_point_chromaticity_y);
  Read(read_cb, reverse_byte_order, &mastering_metadata.luminance_max);
  Read(read_cb, reverse_byte_order, &mastering_metadata.luminance_min);

  Read(read_cb, reverse_byte_order, &color_metadata.max_cll);
  Read(read_cb, reverse_byte_order, &color_metadata.max_fall);
  Read(read_cb, reverse_byte_order, &color_metadata.primaries);
  Read(read_cb, reverse_byte_order, &color_metadata.transfer);
  Read(read_cb, reverse_byte_order, &color_metadata.matrix);
  Read(read_cb, reverse_byte_order, &color_metadata.range);
  for (int i = 0; i < 12; ++i) {
    Read(read_cb, reverse_byte_order, &color_metadata.custom_primary_matrix[i]);
  }
}

void Write(const WriteCB& write_cb,
           SbMediaVideoCodec video_codec,
           const SbMediaVideoSampleInfo& video_sample_info) {
  Write(write_cb, video_codec);
  Write(write_cb, video_sample_info.is_key_frame);
  Write(write_cb, video_sample_info.frame_width);
  Write(write_cb, video_sample_info.frame_height);

#if SB_API_VERSION >= 11
  auto& color_metadata = video_sample_info.color_metadata;
#else   // SB_API_VERSION >= 11
  SB_DCHECK(video_sample_info.color_metadata);
  auto& color_metadata = *video_sample_info.color_metadata;
#endif  // SB_API_VERSION >= 11

  Write(write_cb, color_metadata.bits_per_channel);
  Write(write_cb, color_metadata.chroma_subsampling_horizontal);
  Write(write_cb, color_metadata.chroma_subsampling_vertical);
  Write(write_cb, color_metadata.cb_subsampling_horizontal);
  Write(write_cb, color_metadata.cb_subsampling_vertical);
  Write(write_cb, color_metadata.chroma_siting_horizontal);
  Write(write_cb, color_metadata.chroma_siting_vertical);

  auto& mastering_metadata = color_metadata.mastering_metadata;
  Write(write_cb, mastering_metadata.primary_r_chromaticity_x);
  Write(write_cb, mastering_metadata.primary_r_chromaticity_y);
  Write(write_cb, mastering_metadata.primary_g_chromaticity_x);
  Write(write_cb, mastering_metadata.primary_g_chromaticity_y);
  Write(write_cb, mastering_metadata.primary_b_chromaticity_x);
  Write(write_cb, mastering_metadata.primary_b_chromaticity_y);
  Write(write_cb, mastering_metadata.white_point_chromaticity_x);
  Write(write_cb, mastering_metadata.white_point_chromaticity_y);
  Write(write_cb, mastering_metadata.luminance_max);
  Write(write_cb, mastering_metadata.luminance_min);

  Write(write_cb, color_metadata.max_cll);
  Write(write_cb, color_metadata.max_fall);
  Write(write_cb, color_metadata.primaries);
  Write(write_cb, color_metadata.transfer);
  Write(write_cb, color_metadata.matrix);
  Write(write_cb, color_metadata.range);
  for (int i = 0; i < 12; ++i) {
    Write(write_cb, color_metadata.custom_primary_matrix[i]);
  }
}

}  // namespace video_dmp
}  // namespace player
}  // namespace starboard
}  // namespace shared
}  // namespace starboard
#endif  // SB_HAS(PLAYER_FILTER_TESTS)
