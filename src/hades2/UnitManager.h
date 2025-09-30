//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Unit.h"

namespace sgg {
class UnitManager {
  public:
    static Unit *Get(int id) { return ((Unit * (__fastcall *)(int)) HookTable::Instance().UnitManager_Get)(id); }
    static void Add(Unit *unit, bool needsInitialization) {
        ((void(__fastcall *)(Unit *, bool))HookTable::Instance().UnitManager_Add)(unit, needsInitialization);
    }
};
} // namespace sgg