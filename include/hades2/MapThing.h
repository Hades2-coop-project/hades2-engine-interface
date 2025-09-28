//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "MapThingDef.h"

namespace sgg {
class MapThing {
  public:
    MapThingDef *GetDef() noexcept { return &mDef; };

  private:
    MapThingDef mDef;
};
static_assert(sizeof(MapThing) == 0xD8, "Incorrect sgg::MapThing size");
} // namespace sgg