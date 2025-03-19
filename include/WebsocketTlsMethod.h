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
 * @brief Enum class representing various SSL/TLS protocol methods.
 *
 * The `TlsMethod` enum is used to specify the SSL/TLS version or method
 * for secure communication. It supports a variety of SSL and TLS versions,
 * including specific configurations for client and server roles.
 */
enum class TlsMethod
{
    /// @brief Generic SSL version 2.
    sslv2,

    /// @brief SSL version 2 client configuration.
    sslv2_client,

    /// @brief SSL version 2 server configuration.
    sslv2_server,

    /// @brief Generic SSL version 3.
    sslv3,

    /// @brief SSL version 3 client configuration.
    sslv3_client,

    /// @brief SSL version 3 server configuration.
    sslv3_server,

    /// @brief Generic TLS version 1.0.
    tlsv1,

    /// @brief TLS version 1.0 client configuration.
    tlsv1_client,

    /// @brief TLS version 1.0 server configuration.
    tlsv1_server,

    /// @brief Generic SSL/TLS with automatic protocol negotiation.
    sslv23,

    /// @brief SSL/TLS client with automatic protocol negotiation.
    sslv23_client,

    /// @brief SSL/TLS server with automatic protocol negotiation.
    sslv23_server,

    /// @brief Generic TLS version 1.1.
    tlsv11,

    /// @brief TLS version 1.1 client configuration.
    tlsv11_client,

    /// @brief TLS version 1.1 server configuration.
    tlsv11_server,

    /// @brief Generic TLS version 1.2.
    tlsv12,

    /// @brief TLS version 1.2 client configuration.
    tlsv12_client,

    /// @brief TLS version 1.2 server configuration.
    tlsv12_server,

    /// @brief Generic TLS version 1.3.
    tlsv13,

    /// @brief TLS version 1.3 client configuration.
    tlsv13_client,

    /// @brief TLS version 1.3 server configuration.
    tlsv13_server,

    /// @brief Generic TLS configuration.
    tls,

    /// @brief TLS client configuration.
    tls_client,

    /// @brief TLS server configuration.
    tls_server
};

} // namespace Websocket
