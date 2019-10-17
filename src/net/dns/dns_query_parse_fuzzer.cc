// Copyright (c) 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>

#include "net/base/io_buffer.h"
#include "net/dns/dns_query.h"
#include "starboard/memory.h"
#include "starboard/types.h"

// Entry point for LibFuzzer.
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  auto packet = base::MakeRefCounted<net::IOBufferWithSize>(size);
  SbMemoryCopy(packet->data(), data, size);
  auto out = std::make_unique<net::DnsQuery>(packet);
  out->Parse();
  return 0;
}
