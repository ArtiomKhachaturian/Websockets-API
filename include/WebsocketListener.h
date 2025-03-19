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
#pragma once // WebsocketListener.h
#include <string_view>

// prototype defined in 'Bricks' library,
// see https://github.com/ArtiomKhachaturian/Bricks
namespace Bricks {
class Blob;
}

namespace Websocket
{

class Error;
enum class State;

/**
 * @brief An interface class for listening to websocket events.
 *
 * The `Listener` class defines callback methods for handling various WebSocket events,
 * such as state changes, errors, and incoming messages. Classes that wish to handle these
 * events should inherit from `Listener` and override the necessary methods.
 */
class Listener
{
public:
    /**
     * @brief Called when the websocket state changes.
     *
     * @param socketId The unique identifier of the websocket socket.
     * @param connectionId The unique identifier of the websocket connection.
     * @param state The new state of the websocket connection.
     */
    virtual void onStateChanged(uint64_t /*socketId*/,
                                uint64_t /*connectionId*/,
                                State /*state*/) {}

    /**
     * @brief Called when an error occurs on the websocket connection.
     *
     * @param socketId The unique identifier of the websocket socket.
     * @param connectionId The unique identifier of the websocket connection.
     * @param error Details of the error that occurred.
     */
    virtual void onError(uint64_t /*socketId*/,
                         uint64_t /*connectionId*/,
                         const Error& /*error*/) {}

    /**
     * @brief Called when a text message is received on the websocket connection.
     *
     * @param socketId The unique identifier of the websocket socket.
     * @param connectionId The unique identifier of the websocket connection.
     * @param message The received text message.
     */
    virtual void onTextMessage(uint64_t /*socketId*/,
                               uint64_t /*connectionId*/,
                               const std::string_view& /*message*/) {}

    /**
     * @brief Called when a binary message is received on the websocket connection.
     *
     * @param socketId The unique identifier of the websocket socket.
     * @param connectionId The unique identifier of the websocket connection.
     * @param message The received binary message as a blob.
     */
    virtual void onBinaryMessage(uint64_t /*socketId*/,
                                 uint64_t /*connectionId*/,
                                 const Bricks::Blob& /*message*/) {}

    /**
     * @brief Called when a pong response is received for a ping.
     *
     * @param socketId The unique identifier of the websocket socket.
     * @param connectionId The unique identifier of the websocket connection.
     * @param payload The payload data from the pong response.
     */
    virtual void onPong(uint64_t /*socketId*/,
                        uint64_t /*connectionId*/,
                        const Bricks::Blob& /*payload*/) {}

protected:
    /**
     * @brief Virtual destructor.
     *
     * Ensures proper cleanup of derived classes when deleted via a `Listener` pointer.
     */
    virtual ~Listener() = default;
};

} // namespace Websocket
