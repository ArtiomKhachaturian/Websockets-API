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
#include <memory>

namespace Websocket
{

class EndPoint;

/**
 * @brief An abstract factory class for creating websocket endpoints.
 *
 * The `Factory` class provides an interface for creating instances of `EndPoint`.
 * Derived classes should implement the `create` method to define how `EndPoint`
 * objects are instantiated.
 */
class Factory
{
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Factory() = default;

    /**
     * @brief Creates a new instance of a websocket endpoint.
     *
     * @return A `std::unique_ptr` to the newly created `EndPoint` instance.
     */
    virtual std::unique_ptr<EndPoint> create() const = 0;
};

} // namespace Websocket
