// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/base/cert_database.h"

#include <openssl/x509.h>

#include "base/logging.h"
#include "base/observer_list_threadsafe.h"
#include "net/base/crypto_module.h"
#include "net/base/net_errors.h"
#include "net/base/openssl_private_key_store.h"
#include "net/base/x509_certificate.h"
#include "starboard/types.h"

namespace net {

CertDatabase::CertDatabase()
    : observer_list_(new ObserverListThreadSafe<Observer>) {}

CertDatabase::~CertDatabase() {}

int CertDatabase::CheckUserCert(X509Certificate* cert) {
  if (!cert)
    return ERR_CERT_INVALID;
  if (cert->HasExpired())
    return ERR_CERT_DATE_INVALID;

  if (!OpenSSLPrivateKeyStore::GetInstance()->FetchPrivateKey(
          X509_PUBKEY_get(X509_get_X509_PUBKEY(cert->os_cert_handle()))))
    return ERR_NO_PRIVATE_KEY_FOR_CERT;

  return OK;
}

int CertDatabase::AddUserCert(X509Certificate* cert) {
  NOTIMPLEMENTED();
  return ERR_NOT_IMPLEMENTED;
}

}  // namespace net
