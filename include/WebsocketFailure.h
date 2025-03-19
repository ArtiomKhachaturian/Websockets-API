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
#pragma once // WebsocketFailure.h

namespace Websocket
{

/**
 * @brief Enum class representing various failure types in operations.
 *
 * The `Failure` enum is used to classify different kinds of failures that might occur
 * during operations, providing meaningful labels for error handling and debugging.
 */
enum class Failure
{
    /**
     * @brief General failure.
     *
     * Represents an unspecified or generic failure.
     */
    General,

    /**
     * @brief Failure due to no connection.
     *
     * Indicates that an operation failed because there was no active connection.
     */
    NoConnection,

    /**
     * @brief Failure caused by an issue with a custom header.
     *
     * This type of failure occurs when there is a problem with a custom header in a request.
     */
    CustomHeader,

    /**
     * @brief Failure in writing text data.
     *
     * Indicates that an attempt to write text data failed.
     */
    WriteText,

    /**
     * @brief Failure in writing binary data.
     *
     * Indicates that an attempt to write binary data failed.
     */
    WriteBinary,

    /**
     * @brief Failure due to a socket option issue.
     *
     * This type of failure occurs when there is a problem configuring or using a socket option.
     */
    SocketOption,

    /**
     * @brief Failure in configuring TLS options.
     *
     * Indicates that a problem occurred with TLS (Transport Layer Security) options.
     */
    TlsOptions,

    /**
     * @brief Failure due to a ping operation.
     *
     * Represents a failure in a ping-related operation.
     */
    Ping
};

/**
 * @brief Converts a `Failure` value to its string representation.
 *
 * This function provides a human-readable string for each failure type,
 * making it easier to debug and log error messages.
 *
 * @param failure The `Failure` enum value to convert.
 * @return A constant character pointer representing the string version of the failure.
 */
inline const char* toString(Failure failure) {
    switch (failure) {
        case Failure::General:
            return "general";
        case Failure::NoConnection:
            return "no connection";
        case Failure::CustomHeader:
            return "custom header";
        case Failure::WriteText:
            return "write text";
        case Failure::WriteBinary:
            return "write binary";
        case Failure::SocketOption:
            return "socket option";
        case Failure::TlsOptions:
            return "TLS options";
        case Failure::Ping:
            return "ping";
        default:
            break;
    }
    return "unknown";
}

} // namespace Websocket
