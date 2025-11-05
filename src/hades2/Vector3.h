//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace Vectormath {

class Vector3 {
  public:
    Vector2() : mX{}, mY{}, mZ{} {};
    Vector2(float x, float y, float z) : mX{x}, mY{y}, mZ{z} {};

    float mX, mY;
};

} // namespace Vectormath