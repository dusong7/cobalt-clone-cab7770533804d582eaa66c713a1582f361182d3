# Copyright 2018 The Cobalt Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This file was initially generated by starboard/tools/create_derived_build.py,
# though it may have been modified since its creation.


from starboard.linux.shared import gyp_configuration as parent_configuration

class LinuxX86Configuration(parent_configuration.LinuxConfiguration):
  """Starboard Linux x86 Platform Configuration."""

  def __init__(self):
    self.host_compiler_environment = {
        'CC_host': '/usr/bin/clang',
        'CXX_host': '/usr/bin/clang++',
        'LD_host': '/usr/bin/clang++',
        'ARFLAGS_host': 'rcs',
        'ARTHINFLAGS_host': 'rcsT',
    }
    super(LinuxX86Configuration, self).__init__('linux-x86x11')

def CreatePlatformConfig():
  return LinuxX86Configuration()
