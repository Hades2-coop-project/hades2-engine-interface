//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Entity.h"
#include "HashGuid.h"
#include "HookTable.h"

namespace sgg {
class EntityManager {
  public:
    Entity *Create(Entity *result, HashGuid name) {
        return ((Entity * (__fastcall *)(void *, Entity *, HashGuid)) HookTable::Instance().EntityManager_Create)(this, result, name);
    }

    static EntityManager *GetInstance() { return *(EntityManager **)HookTable::Instance().UnitManager_ENTITY_MANAGER; }
};
} // namespace sgg