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

#include "starboard/player.h"

#include "starboard/common/log.h"
#include "starboard/shared/starboard/player/player_internal.h"

#if SB_API_VERSION >= 10
void SbPlayerWriteSample2(SbPlayer player,
                          SbMediaType sample_type,
                          const SbPlayerSampleInfo* sample_infos,
                          int number_of_sample_infos) {
  SB_DCHECK(number_of_sample_infos == 1);

  if (!SbPlayerIsValid(player)) {
    SB_DLOG(WARNING) << "player is invalid.";
    return;
  }

#if SB_API_VERSION >= 11
  player->WriteSample(*sample_infos);
#else   // SB_API_VERSION >= 11
  player->WriteSample(sample_type, *sample_infos);
#endif  // SB_API_VERSION >= 11
}
#endif  // SB_API_VERSION >= 10
