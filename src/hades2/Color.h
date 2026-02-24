//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class Color {
  public:
    Color() : mColor(0) {};
    Color(uint32_t color) : mColor{color} {};
  private:
    uint32_t mColor;
};
static_assert(sizeof(Color) == 0x4, "Incorrect sgg::Color size");
} // namespace sgg