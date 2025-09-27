//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Entity.h"
#include "HookTable.h"
#include "MapThing.h"
#include "Unit.h"
#include "UnitData.h"

namespace sgg {
__declspec(align(16)) class PlayerUnit : public Unit {
  public:
    static void internal_constructor(void *pos, sgg::Entity entity, sgg::UnitData *data, sgg::MapThing *mapThing,
                                     Vectormath::Vector2 location) {
        ((void(__fastcall *)(void *, sgg::Entity, sgg::UnitData *, sgg::MapThing *,
                             Vectormath::Vector2))HookTable::Instance()
             .PlayerUnit_PlayerUnit)(pos, entity, data, mapThing, location);
    };

    uint8_t pad[0x10];
};
static_assert(sizeof(PlayerUnit) == 0x850, "Incorrect sgg::PlayerUnit size");
} // namespace sgg
