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

enum class Failure
{
    General,
    NoConnection,
    CustomHeader,
    WriteText,
    WriteBinary,
    SocketOption,
    TlsOptions
};

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
        default:
            break;
    }
    return "unknown";
}

} // namespace Websocket
