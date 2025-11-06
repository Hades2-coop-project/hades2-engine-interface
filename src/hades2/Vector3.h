//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace Vectormath {

class Vector3 {
  public:
    Vector3() : mX{}, mY{}, mZ{} {};
    Vector3(float x, float y, float z) : mX{x}, mY{y}, mZ{z} {};

    union {
        struct {
            float mX, mY, mZ;
        };
        __m128 mVec128;
    };
};
static_assert(sizeof(Vector3) == 0x10, "Invalid Vectormath::Vector3 size");

} // namespace Vectormath