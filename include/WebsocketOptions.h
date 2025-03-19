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
#include "WebsocketTls.h"
#include <optional>
#include <unordered_map>

namespace Websocket
{

/**
 * @brief Represents configurable options for a connection.
 *
 * The `Options` struct provides a set of parameters for configuring socket options,
 * headers, and SSL/TLS settings. These settings offer fine-grained control over
 * connection behavior and properties.
 */
struct Options
{
    /**
     * @brief Type alias for SO_LINGER options.
     *
     * Represents the linger setting as a pair, where the first element indicates
     * if linger is enabled, and the second element specifies the duration (in seconds).
     */
    using Linger = std::pair<bool, uint16_t>;

public:
    /**
     * @brief The host URL or URI for the connection.
     *
     * Specifies the destination address for the connection.
     */
    std::string _host;

    /**
     * @brief The user agent string.
     *
     * Specifies the agent identifier, often used in HTTP headers.
     */
    std::string _userAgent;

    /**
     * @brief Additional headers for the connection.
     *
     * Allows the inclusion of extra HTTP headers as key-value pairs.
     */
    std::unordered_map<std::string, std::string> _extraHeaders;

    // Socket options

    /**
     * @brief Enables or disables broadcasting (SO_BROADCAST).
     *
     * If set to true, the connection supports broadcasting.
     */
    std::optional<bool> _broadcast;

    /**
     * @brief Enables or disables routing (SO_DONTROUTE).
     *
     * If set to true, the connection will bypass the routing tables.
     */
    std::optional<bool> _doNotRoute;

    /**
     * @brief Enables or disables keep-alive (SO_KEEPALIVE).
     *
     * If set to true, the connection will use keep-alive packets to maintain the connection.
     */
    std::optional<bool> _keepAlive;

    /**
     * @brief Configures the linger setting (SO_LINGER).
     *
     * If enabled, the linger setting determines how the connection handles pending data
     * when the socket is closed.
     * @see https://www.ibm.com/docs/en/cics-tg-multi/9.2?topic=settings-so-linger-setting
     */
    std::optional<Linger> _linger;

    /**
     * @brief Configures the receive buffer size (SO_RCVBUF).
     *
     * Specifies the size (in bytes) of the buffer used for receiving data.
     */
    std::optional<uint32_t> _receiveBufferSize;

    /**
     * @brief Configures the receive low watermark (SO_RCVLOWAT).
     *
     * Specifies the minimum amount of data (in bytes) required to trigger a read operation.
     */
    std::optional<uint32_t> _receiveLowWatermark;

    /**
     * @brief Enables or disables address reuse (SO_REUSEADDR).
     *
     * If set to true, the socket allows binding to an address that is in use.
     */
    std::optional<bool> _reuseAddress;

    /**
     * @brief Configures the send buffer size (SO_SNDBUF).
     *
     * Specifies the size (in bytes) of the buffer used for sending data.
     */
    std::optional<uint32_t> _sendBufferSize;

    /**
     * @brief Configures the send low watermark (SO_SNDLOWAT).
     *
     * Specifies the minimum amount of data (in bytes) required to trigger a send operation.
     */
    std::optional<uint32_t> _sendLowWatermark;

    /**
     * @brief Enables or disables the Nagle algorithm (TCP_NODELAY).
     *
     * If set to true, disables the Nagle algorithm, reducing latency for small packets.
     */
    std::optional<bool> _tcpNoDelay;

    // SSL/TLS settings

    /**
     * @brief SSL/TLS configuration options.
     *
     * Provides settings for secure communication, including certificate paths
     * and protocol versions.
     */
    Tls _tls;
};

} // namespace Websocket
