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

namespace Websocket
{

/**
 * @brief Enum class to specify the level of TLS peer verification.
 *
 * The `TlsPeerVerification` enum defines the behavior for verifying the identity
 * of the TLS peer during a secure connection handshake.
 */
enum class TlsPeerVerification
{
    /**
     * @brief No peer verification.
     *
     * Indicates that the peer's identity will not be verified during the TLS handshake.
     * This option is insecure and should only be used for testing or debugging purposes.
     */
    No,

    /**
     * @brief Enable peer verification.
     *
     * The peer's certificate will be verified during the TLS handshake to ensure authenticity.
     */
    Yes,

    /**
     * @brief Enable peer verification and reject if no certificate is provided.
     *
     * The peer's certificate will be verified, and the connection will be rejected
     * if the peer fails to provide a valid certificate.
     */
    YesAndRejectIfNoCert
};

} // namespace Websocket
