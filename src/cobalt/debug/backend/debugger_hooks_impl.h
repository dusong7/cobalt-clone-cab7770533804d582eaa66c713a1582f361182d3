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
#ifndef COBALT_DEBUG_BACKEND_DEBUGGER_HOOKS_IMPL_H_
#define COBALT_DEBUG_BACKEND_DEBUGGER_HOOKS_IMPL_H_

#include <string>

#include "cobalt/base/debugger_hooks.h"

namespace cobalt {

namespace script {
class ScriptDebugger;
}  // namespace script

namespace debug {
namespace backend {

class DebugModule;

class DebuggerHooksImpl : public base::DebuggerHooks {
 public:
  void AsyncTaskScheduled(void* task, const std::string& name,
                          bool recurring) const override;
  void AsyncTaskStarted(void* task) const override;
  void AsyncTaskFinished(void* task) const override;
  void AsyncTaskCanceled(void* task) const override;

 private:
  // Only DebugModule can attach/detach the debugger.
  friend class backend::DebugModule;

  void AttachDebugger(script::ScriptDebugger* script_debugger);
  void DetachDebugger();

  script::ScriptDebugger* script_debugger_ = nullptr;
};

}  // namespace backend
}  // namespace debug
}  // namespace cobalt

#endif  // COBALT_DEBUG_BACKEND_DEBUGGER_HOOKS_IMPL_H_
