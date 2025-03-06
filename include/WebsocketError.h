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
#pragma once // WebsocketError.h
#include "WebsocketFailure.h"
#include <sstream>
#include <string>
#include <system_error>

namespace Websocket
{

struct Error
{
    Failure _failure = {};
    std::error_code _code;
    std::string _details;
};

} // Websocket


inline std::ostream& operator << (std::ostream& os,
                                  const Websocket::Error& error) {
    os << toString(error._failure) << " error";
    const auto message = error._code.message();
    if (!message.empty()) {
        os << " - '" << message << "'";
    }
    os << ", error code #" << error._code.value();
    os << ", category '" << error._code.category().name() << "'";
    if (!error._details.empty() && message != error._details) {
        os << ", details - '" << error._details << "'";
    }
    return os;
}

namespace Websocket {

inline std::string toString(const Error& error) {
    std::ostringstream stream;
    stream << error;
    return stream.str();
}

}
