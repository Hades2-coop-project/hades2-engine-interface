//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include <cstdint>

#define GET_HOOK(name, type) (reinterpret_cast<type>(HookTable::Instance().name))

class lua_State;

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

    uintptr_t EntityManager_Create;
    uintptr_t HashGuid_StringIntern;
    uintptr_t GameDataManager_GetAnimationData;
    uintptr_t HashGuid_c_str;


    uintptr_t _aligned_malloc;

    uintptr_t MenuScreen_constructor;
    uintptr_t MenuScreen_destructor;
    uintptr_t MenuScreen_constructor_ScreenManager;
    uintptr_t MenuScreen_CreateBack;
    uintptr_t MenuScreen_CreateBackground;
    uintptr_t MenuScreen_CreateTitleText;
    uintptr_t MenuScreen_CreateCancelButton;
    uintptr_t MenuScreen_vft;

    uintptr_t MainMenuScreen_MainMenuScreen;
    uintptr_t MainMenuScreen_OpenProfiles;

    uintptr_t GUIComponentButton_GUIComponentButton_MenuScreen;
    uintptr_t GUIComponentButton_UseDefaultText;

    uintptr_t GUIComponentTextBox_GUIComponentTextBox;

    uintptr_t vector8x8_push;

    uintptr_t GUIComponentReflectionHelper_ReflectComponent_GUIComponentButton;
    uintptr_t GUIComponentReflectionHelper_ReflectComponent_GUIComponentTextBox;

    uintptr_t ScreenManager_AddScreen_screen;

    uintptr_t ScreenData_ReadXml;

    uintptr_t fsSetPathForResourceDir;
    uintptr_t gResourceDirectories;

    uintptr_t luaL_getsubtable;
    uintptr_t lua_rawseti;
};
