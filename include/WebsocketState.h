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
#pragma once // WebsocketState.h

namespace Websocket
{

/**
 * @brief Enum class representing the states of a websocket connection.
 *
 * The `State` enum is used to track the current status of a WebSocket connection,
 * from the initial connection process to disconnection.
 */
enum class State
{
    /**
     * @brief The websocket is in the process of connecting.
     *
     * This state indicates that a connection is being established.
     */
    Connecting,

    /**
     * @brief The websocket is connected and ready for communication.
     *
     * This state indicates that the connection has been successfully established.
     */
    Connected,

    /**
     * @brief The websocket is in the process of disconnecting.
     *
     * This state indicates that the connection is being closed.
     */
    Disconnecting,

    /**
     * @brief The websocket has been disconnected.
     *
     * This state indicates that the connection has been fully closed.
     */
    Disconnected,
};


} // namespace Websocket
