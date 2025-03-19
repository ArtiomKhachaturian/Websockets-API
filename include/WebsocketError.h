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

/**
 * @brief Represents an error with detailed information about its cause.
 *
 * The `Error` struct is used to encapsulate information about a failure,
 * including the failure type, an error code, and additional details.
 */
struct Error
{
    /**
     * @brief The type of failure that occurred.
     *
     * Encapsulates the general cause of the error using the `Failure` enum.
     */
    Failure _failure = {};

    /**
     * @brief A platform-specific error code.
     *
     * Contains an `std::error_code` object, which provides detailed information
     * about the error that occurred, including its category and numeric value.
     */
    std::error_code _code;

    /**
     * @brief A string with additional error details.
     *
     * Provides human-readable information about the error to aid debugging.
     */
    std::string _details;
};

} //  namespace Websocket

/**
 * @brief Overloads the `<<` operator to output the `Error` object in a readable format.
 *
 * This function formats the contents of the `Error` structure for easy logging
 * or display. It includes the failure type, error code, and additional details.
 *
 * @param os The output stream where the error details will be written.
 * @param error The `Error` object to output.
 * @return A reference to the output stream for chaining operations.
 */
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

/**
 * @brief Converts an `Error` object to its string representation.
 *
 * This function formats the contents of the `Error` structure into a single
 * human-readable string, including the failure type, error code, and details.
 * It is useful for debugging and logging errors in a concise format.
 *
 * @param error The `Error` object to convert.
 * @return A `std::string` containing the formatted representation of the error.
 */
inline std::string toString(const Error& error) {
    std::ostringstream stream;
    stream << error;
    return stream.str();
}

} // namespace Websocket
