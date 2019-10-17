// Usually this would be:
//
// Generated by build/write_buildflag_header.py
// From "//net:features"
//
// However for Cobalt we just hardcode the values of these #defines.

#ifndef NET_NET_FEATURES_H_
#define NET_NET_FEATURES_H_

#include "base/buildflag.h"

#define BUILDFLAG_INTERNAL_POSIX_AVOID_MMAP() (0)
#define BUILDFLAG_INTERNAL_DISABLE_FILE_SUPPORT() (1)
#define BUILDFLAG_INTERNAL_DISABLE_FTP_SUPPORT() (1)
#define BUILDFLAG_INTERNAL_ENABLE_MDNS() (1)
#define BUILDFLAG_INTERNAL_ENABLE_REPORTING() (1)
#define BUILDFLAG_INTERNAL_ENABLE_WEBSOCKETS() (1)
#define BUILDFLAG_INTERNAL_INCLUDE_TRANSPORT_SECURITY_STATE_PRELOAD_LIST() (1)

#endif  // NET_NET_FEATURES_H_
