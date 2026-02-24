//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class Rectangle {
  private:
    float x;
    float y;
    float w;
    float h;
};

static_assert(sizeof(Rectangle) == 0x10, "Incorrect sgg::Rectangle size");
} // namespace sgg
