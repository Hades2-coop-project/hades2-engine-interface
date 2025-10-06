//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "../HookTable.h"
#include "Obstacle.h"

namespace sgg {
class Thing;

class World {
  public:
    Thing *GetActiveThing(size_t id) {
        return ((Thing * (__fastcall *)(void *, int)) HookTable::Instance().World_GetActiveThing)(this, id);
    }

    Obstacle * CreateThing(MapThing *mapThing, bool luaCallback, bool mapThingLuaCallback) {
        return ((Obstacle * (__fastcall *)(void *, MapThing*, bool, bool)) HookTable::Instance().World_CreateThing)(
            this, mapThing, luaCallback, mapThingLuaCallback);
    }


    static World *Instance() { return reinterpret_cast<World*>(HookTable::Instance().world); }
};
} // namespace SGG