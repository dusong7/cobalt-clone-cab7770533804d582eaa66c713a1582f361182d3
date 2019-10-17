// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_BASE_TRACE_CONSTANTS_H_
#define NET_BASE_TRACE_CONSTANTS_H_

namespace net {

#if defined(COBALT_QUIC46)
// Net Category used in Tracing.
constexpr const char* NetTracingCategory() {
  // Declared as a constexpr function to have an external linkage and to be
  // known at compile-time.
  return "disabled-by-default-net";
}
#endif

// Net Category used in Tracing.
extern const char kNetTracingCategory[];

}  // namespace net

#endif  // NET_BASE_TRACE_CONSTANTS_H_
