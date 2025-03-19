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
#pragma once // WebsocketEndPoint.h
#include "WebsocketState.h"
#include "WebsocketCloseCode.h"
#include "WebsocketOptions.h"
#include <memory>
#include <string>

// prototype defined in 'Bricks' library,
// see https://github.com/ArtiomKhachaturian/Bricks
namespace Bricks {
class Blob;
}

namespace Websocket
{

class Listener;
enum class State;

/**
 * @brief Abstract base class representing a websocket endpoint.
 *
 * The `EndPoint` class provides an interface for managing websocket connections,
 * including opening and closing connections, sending messages, and tracking connection states.
 */
class EndPoint
{
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~EndPoint() = default;

    /**
     * @brief Sets the listener for websocket events.
     *
     * The listener handles events such as state changes, errors, and incoming messages.
     *
     * @param listener A shared pointer to a `Listener` object.
     */
    virtual void setListener(const std::shared_ptr<Listener>& listener) = 0;

    /**
     * @brief Opens a websocket connection with the specified options.
     *
     * The [connectionId] is passed to all methods of the listener for context.
     *
     * @param options The configuration options for the websocket connection.
     * @param connectionId An optional identifier for the connection (default: 0).
     * @return `true` if the connection was successfully opened, otherwise `false`.
     */
    virtual bool open(Options options, uint64_t connectionId = 0U) = 0;

    /**
     * @brief Closes the websocket connection.
     *
     * Gracefully shuts down the connection and notifies the listener of state changes.
     */
    virtual void close() = 0;

    /**
     * @brief Retrieves the host address of the websocket connection.
     *
     * @return A string representing the host address.
     */
    virtual std::string host() const = 0;

    /**
     * @brief Retrieves the current state of the websocket connection.
     *
     * @return The `State` enum value representing the current connection state.
     */
    virtual State state() const = 0;

    /**
     * @brief Sends a binary message over the websocket connection.
     *
     * @param binary The binary message to send as a `Bricks::Blob`.
     * @return `true` if the message was successfully sent, otherwise `false`.
     */
    virtual bool sendBinary(const Bricks::Blob& binary) = 0;

    /**
     * @brief Sends a text message over the websocket connection.
     *
     * @param text The text message to send as a `std::string_view`.
     * @return `true` if the message was successfully sent, otherwise `false`.
     */
    virtual bool sendText(std::string_view text) = 0;

    /**
     * @brief Sends a ping message with a payload over the websocket connection.
     *
     * The server is expected to respond with a pong message containing the same payload.
     *
     * @param payload The ping message payload as a `Bricks::Blob`.
     * @return `true` if the ping was successfully sent, otherwise `false`.
     */
    virtual bool ping(const Bricks::Blob& payload) = 0;

    /**
     * @brief Sends a ping message without a payload over the websocket connection.
     *
     * @return `true` if the ping was successfully sent, otherwise `false`.
     */
    virtual bool ping() = 0;

    /**
     * @brief Resets the listener by setting it to `nullptr`.
     */
    void resetListener() { setListener({}); }

    /**
     * @brief Retrieves the unique identifier for this endpoint.
     *
     * @return A unique identifier as a 64-bit unsigned integer.
     */
    uint64_t id() const noexcept { return reinterpret_cast<uint64_t>(this); }
};

} // namespace Websocket
