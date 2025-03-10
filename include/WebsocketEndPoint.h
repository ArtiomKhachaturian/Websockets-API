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

class EndPoint
{
public:
    virtual ~EndPoint() = default;
    virtual void setListener(const std::shared_ptr<Listener>& listener) = 0;
    // [connectionId] will passed to all methods of the listener
    virtual bool open(Options options, uint64_t connectionId = 0U) = 0;
    virtual void close() = 0;
    virtual std::string host() const = 0;
    virtual State state() const = 0;
    virtual bool sendBinary(const Bricks::Blob& binary) = 0;
    virtual bool sendText(std::string_view text) = 0;
    virtual bool ping(const Bricks::Blob& payload) = 0;
    virtual bool ping() = 0;
    void resetListener() { setListener({}); }
    uint64_t id() const noexcept { return reinterpret_cast<uint64_t>(this); }
};

} // namespace Websocket
