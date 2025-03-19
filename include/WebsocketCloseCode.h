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
#include <cstdint>
    
namespace Websocket
{

/**
 * @brief Namespace containing WebSocket close codes as defined by the WebSocket protocol.
 *
 * These codes indicate the reason for the closure of a WebSocket connection.
 * For detailed information, refer to the WebSocket protocol documentation or
 * the GitHub repository at https://github.com/Luka967/websocket-close-codes.
 */
namespace CloseCode
{
    /**
     * @brief Normal closure of the WebSocket connection.
     *
     * This indicates that the connection was closed gracefully with no issues.
     */
    static const uint16_t Normal = 1000;

    /**
     * @brief Closure due to the endpoint going away.
     *
     * This may occur when the server shuts down or the client navigates away.
     */
    static const uint16_t GoingAway = 1001;

    /**
     * @brief Closure due to a protocol error.
     *
     * This indicates that a WebSocket protocol violation occurred.
     */
    static const uint16_t ProtocolError = 1002;

    /**
     * @brief Closure due to unsupported data.
     *
     * This happens when a data format or message type is not supported.
     */
    static const uint16_t UnsupportedData = 1003;

    /**
     * @brief Reserved. Indicates that no status code was provided.
     *
     * This is used internally and not transmitted over the wire.
     */
    static const uint16_t NoStatus = 1005;

    /**
     * @brief Abnormal closure of the WebSocket connection.
     *
     * This is used to indicate that the connection closed without a proper close control frame.
     */
    static const uint16_t AbnormalClose = 1006;

    /**
     * @brief Closure due to invalid payload data.
     *
     * This occurs when the received data is not consistent with the message type.
     */
    static const uint16_t InvalidPayload = 1007;

    /**
     * @brief Closure due to a policy violation.
     *
     * This indicates that a policy constraint has been violated.
     */
    static const uint16_t PolicyViolation = 1008;

    /**
     * @brief Closure due to a message that is too large.
     *
     * This happens when the size of the message exceeds the allowed limit.
     */
    static const uint16_t MessageTooBig = 1009;

    /**
     * @brief Closure due to a missing required extension.
     *
     * This is sent when a necessary WebSocket extension is not available.
     */
    static const uint16_t ExtensionRequired = 1010;

    /**
     * @brief Closure due to an internal server error.
     *
     * Indicates that the server encountered an unexpected condition that prevented it from fulfilling the request.
     */
    static const uint16_t InternalEndpointError = 1011;

    /**
     * @brief Closure due to a service restart.
     *
     * This is sent when the service is restarted and the connection is closed as a result.
     */
    static const uint16_t serviceRestart = 1012;

    /**
     * @brief Closure due to a temporary condition.
     *
     * Indicates that the client should try reconnecting later.
     */
    static const uint16_t TryAgainLater = 1013;

    /**
     * @brief Closure due to a bad gateway.
     *
     * Indicates that an intermediary server or proxy encountered an error.
     */
    static const uint16_t BadGateway = 1014;

    /**
     * @brief Closure due to a failure in the TLS handshake.
     *
     * This occurs when the WebSocket connection could not be established due to TLS issues.
     */
    static const uint16_t TlsHandshake = 1015;
};

} // namespace Websocket
