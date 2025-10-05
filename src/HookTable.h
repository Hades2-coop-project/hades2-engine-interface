//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include <cstdint>

struct HookTable {
    static HookTable &Instance();
    void Init(const HookTable &parent);

#ifdef HADES2_MOD_LOADER
    using GetSymbolAddress_t = uint64_t(__cdecl *)(const char *symbolName);
    void Init(HookTable::GetSymbolAddress_t GetSymbolAddress);
#endif //  HADES2_MOD_LOADER

    uintptr_t luaState;
    uintptr_t lua_pcallk;
    uintptr_t luaL_loadbufferx;
    uintptr_t HandleAssert;

    uintptr_t PlayerManager_Instance;
    uintptr_t PlayerManager_AddPlayer;
    uintptr_t PlayerManager_AssignController;

    uintptr_t Player_Player;

    uintptr_t PlayerUnit_PlayerUnit;

    uintptr_t UnitManager_ENTITY_MANAGER;
    uintptr_t UnitManager_Add;
    uintptr_t UnitManager_Get;

    uintptr_t Unit_Delete;
    uintptr_t Interact_Use;
    uintptr_t World_GetActiveThing;
    uintptr_t World_CreateThing;
    uintptr_t world;

    uintptr_t GameDataManager_GetUnitData;
};
