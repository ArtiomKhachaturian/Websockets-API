// Copyright 2025 Artiom Khachaturian
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
#pragma once
#include "WebsocketTlsPeerVerification.h"
#include "WebsocketTlsMethod.h"
#include <string>

namespace Websocket
{

/**
 * @brief Represents the configuration for TLS (Transport Layer Security) settings.
 *
 * The `Tls` struct provides options to configure various aspects of TLS,
 * including protocol versions, certificates, and cryptographic parameters.
 */
struct Tls
{
    /**
     * @brief The TLS method or protocol to use.
     *
     * Specifies the version or method of SSL/TLS to be used (e.g., `sslv23`, `tlsv1_2`, etc.).
     */
    TlsMethod _method = TlsMethod::sslv23;

    /**
     * @brief The level of TLS peer verification to perform.
     *
     * Determines whether and how the identity of the peer is verified during the handshake.
     */
    TlsPeerVerification _peerVerification = TlsPeerVerification::No;

    /**
     * @brief Indicates if the certificate is in PEM format.
     *
     * If true, the certificate is in PEM format; otherwise, it is in ASN.1 format.
     */
    bool _certificateIsPem = true;

    /**
     * @brief Always create a new key when using the Diffie-Hellman (_dh) parameter.
     *
     * Ensures that a new key is generated each time to provide perfect forward secrecy.
     */
    bool _dhSingle = true;

    /**
     * @brief Disable SSL version 2.
     *
     * If true, SSLv2 is disabled for security reasons.
     */
    bool _sslv2No = true;

    /**
     * @brief Disable SSL version 3.
     *
     * If true, SSLv3 is disabled for security reasons.
     */
    bool _sslv3No = true;

    /**
     * @brief Disable TLS version 1.0.
     *
     * If true, TLSv1.0 is disabled for security reasons.
     */
    bool _tlsv1No = true;

    /**
     * @brief Disable TLS version 1.1.
     *
     * If true, TLSv1.1 is disabled for security reasons.
     */
    bool _tlsv1_1No = true;

    /**
     * @brief Disable TLS version 1.2.
     *
     * If true, TLSv1.2 is disabled; if false, it is enabled.
     */
    bool _tlsv1_2No = false;

    /**
     * @brief Disable TLS version 1.3.
     *
     * If true, TLSv1.3 is disabled; if false, it is enabled.
     */
    bool _tlsv1_3No = false;

    /**
     * @brief Disable SSL compression even if supported.
     *
     * If true, SSL compression is disabled to prevent attacks like CRIME.
     */
    bool _sslNoCompression = false;

    /**
     * @brief Path or content of the certificate to be used.
     *
     * Specifies the certificate for the TLS connection in PEM or ASN.1 format.
     */
    std::string _certificate;

    /**
     * @brief Path or content of the private key corresponding to the certificate.
     *
     * Specifies the private key for the TLS certificate.
     */
    std::string _certificatePrivateKey;

    /**
     * @brief Password for the private key.
     *
     * If the private key is encrypted, this password is required to decrypt it.
     */
    std::string _certificatePrivateKeyPassword;

    /**
     * @brief Path to the trust store.
     *
     * Specifies the location of the trust store used to verify peer certificates.
     */
    std::string _trustStore;

    /**
     * @brief Cipher suite configuration.
     *
     * Specifies the allowed SSL/TLS ciphers for the connection.
     */
    std::string _sslCiphers;

    /**
     * @brief Diffie-Hellman parameters.
     *
     * Specifies custom Diffie-Hellman parameters to be used for key exchange.
     */
    std::string _dh;
};

} // namespace Websocket
