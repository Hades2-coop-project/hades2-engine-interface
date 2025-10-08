//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Thing.h"
#include <cstdint>

namespace sgg {
__declspec(align(16)) class Obstacle : public Thing {
  public:

    uint8_t pad[368];
};
static_assert(sizeof(Obstacle) == 0x7C0, "Incorrect sgg::Obstacle size");
} // namespace sgg
