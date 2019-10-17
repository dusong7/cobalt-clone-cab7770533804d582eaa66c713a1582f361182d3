// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/http/http_auth_preferences.h"

#include <string>
#include <vector>

#include "base/callback.h"
#include "base/run_loop.h"
#include "base/single_thread_task_runner.h"
#include "base/threading/thread.h"
#include "build/build_config.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace net {

TEST(HttpAuthPreferencesTest, DisableCnameLookup) {
  HttpAuthPreferences http_auth_preferences;
  EXPECT_FALSE(http_auth_preferences.NegotiateDisableCnameLookup());
  http_auth_preferences.set_negotiate_disable_cname_lookup(true);
  EXPECT_TRUE(http_auth_preferences.NegotiateDisableCnameLookup());
}

TEST(HttpAuthPreferencesTest, NegotiateEnablePort) {
  HttpAuthPreferences http_auth_preferences;
  EXPECT_FALSE(http_auth_preferences.NegotiateEnablePort());
  http_auth_preferences.set_negotiate_enable_port(true);
  EXPECT_TRUE(http_auth_preferences.NegotiateEnablePort());
}

#if defined(OS_POSIX)
TEST(HttpAuthPreferencesTest, DisableNtlmV2) {
  HttpAuthPreferences http_auth_preferences;
  EXPECT_TRUE(http_auth_preferences.NtlmV2Enabled());
  http_auth_preferences.set_ntlm_v2_enabled(false);
  EXPECT_FALSE(http_auth_preferences.NtlmV2Enabled());
}
#endif

#if defined(OS_ANDROID)
TEST(HttpAuthPreferencesTest, AuthAndroidhNegotiateAccountType) {
  HttpAuthPreferences http_auth_preferences;
  EXPECT_EQ(std::string(),
            http_auth_preferences.AuthAndroidNegotiateAccountType());
  http_auth_preferences.set_auth_android_negotiate_account_type("foo");
  EXPECT_EQ(std::string("foo"),
            http_auth_preferences.AuthAndroidNegotiateAccountType());
}
#endif

TEST(HttpAuthPreferencesTest, AuthServerWhitelist) {
  HttpAuthPreferences http_auth_preferences;
  // Check initial value
  EXPECT_FALSE(http_auth_preferences.CanUseDefaultCredentials(GURL("abc")));
  http_auth_preferences.SetServerWhitelist("*");
  EXPECT_TRUE(http_auth_preferences.CanUseDefaultCredentials(GURL("abc")));
}

TEST(HttpAuthPreferencesTest, AuthDelegateWhitelist) {
  HttpAuthPreferences http_auth_preferences;
  // Check initial value
  EXPECT_FALSE(http_auth_preferences.CanDelegate(GURL("abc")));
  http_auth_preferences.SetDelegateWhitelist("*");
  EXPECT_TRUE(http_auth_preferences.CanDelegate(GURL("abc")));
}

}  // namespace net
