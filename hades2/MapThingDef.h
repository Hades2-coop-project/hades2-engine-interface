//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HashGuid.h"

namespace sgg {
class MapThingDef {
  public:
    HashGuid GetName() const { return mName; };
    void SetId(uint32_t id) { mId = id; };

  private:
    uint8_t mDataType;
    HashGuid mName;
    Vectormath::Vector2 mLocation;
    uint32_t mId;
    uint8_t pad[196];
};
static_assert(sizeof(MapThingDef) == 0xD8, "Incorrect sgg::MapThingDef size");
} // namespace sgg