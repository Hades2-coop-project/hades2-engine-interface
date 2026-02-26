//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#include "HookTable.h"

static HookTable g_HookTable{};

HookTable& HookTable::Instance() {
    return g_HookTable;
}

void HookTable::Init(const HookTable& parent) {
	g_HookTable = parent;
}

#ifdef HADES2_MOD_LOADER
void HookTable::Init(HookTable::GetSymbolAddress_t GetSymbolAddress) {
    luaState = GetSymbolAddress("sgg::ScriptManager::LuaInterface");
    lua_pcallk = GetSymbolAddress("lua_pcallk");
    luaL_loadbufferx = GetSymbolAddress("luaL_loadbufferx");
    HandleAssert = GetSymbolAddress("sgg__HandleAssert");

    PlayerManager_Instance = GetSymbolAddress("sgg::PlayerManager::Instance");
    PlayerManager_AddPlayer = GetSymbolAddress("sgg::PlayerManager::AddPlayer");
    PlayerManager_AssignController = GetSymbolAddress("sgg::PlayerManager::AssignController");
    Player_Player = GetSymbolAddress("sgg::Player::Player");
    PlayerUnit_PlayerUnit = GetSymbolAddress("sgg::PlayerUnit::PlayerUnit");

    UnitManager_ENTITY_MANAGER = GetSymbolAddress("sgg::UnitManager::ENTITY_MANAGER");
    UnitManager_Add = GetSymbolAddress("sgg::UnitManager::Add");
    UnitManager_Get = GetSymbolAddress("sgg::UnitManager::Get");

    Unit_Delete = GetSymbolAddress("sgg::Unit::Delete");
    Interact_Use = GetSymbolAddress("sgg::Interact::Use");

    World_GetActiveThing = GetSymbolAddress("sgg::World::GetActiveThing");
    World_CreateThing = GetSymbolAddress("sgg::World::CreateThing");
    world = GetSymbolAddress("sgg::world");

    GameDataManager_GetUnitData = GetSymbolAddress("sgg::GameDataManager::GetUnitData");
    EntityManager_Create = GetSymbolAddress("sgg::EntityManager::Create");
    HashGuid_StringIntern = GetSymbolAddress("?StringIntern@HashGuid@sgg@@SAIPEBD_K@Z");
    GameDataManager_GetAnimationData = GetSymbolAddress("sgg::GameDataManager::GetAnimationData");
    HashGuid_c_str = GetSymbolAddress("?c_str@HashGuid@sgg@@QEBAPEBDXZ");

    _aligned_malloc = GetSymbolAddress("__imp__aligned_malloc");

    MenuScreen_constructor = GetSymbolAddress("sgg::MenuScreen::MenuScreen");
    MenuScreen_destructor = GetSymbolAddress("sgg::MenuScreen::~MenuScreen");
    MenuScreen_constructor_ScreenManager = GetSymbolAddress("??0MenuScreen@sgg@@QEAA@PEAVScreenManager@1@@Z");


    MenuScreen_CreateBack = GetSymbolAddress("sgg::MenuScreen::CreateBack");
    MenuScreen_CreateBackground = GetSymbolAddress("sgg::MenuScreen::CreateBackground");
    MenuScreen_CreateTitleText = GetSymbolAddress("sgg::MenuScreen::CreateTitleText");
    MenuScreen_CreateCancelButton = GetSymbolAddress("sgg::MenuScreen::CreateCancelButton");
    MenuScreen_vft = GetSymbolAddress("??_7MenuScreen@sgg@@6BGameScreen@1@@");

    MainMenuScreen_MainMenuScreen = GetSymbolAddress("sgg::MainMenuScreen::MainMenuScreen");
    MainMenuScreen_OpenProfiles = GetSymbolAddress("sgg::MainMenuScreen::OpenProfiles");
    GUIComponentButton_GUIComponentButton_MenuScreen = GetSymbolAddress("??0GUIComponentButton@sgg@@QEAA@PEAVMenuScreen@1@@Z");
    GUIComponentButton_UseDefaultText = GetSymbolAddress("?UseDefaultText@GUIComponentButton@sgg@@UEAAXXZ");

    GUIComponentTextBox_GUIComponentTextBox =
        GetSymbolAddress("??0GUIComponentTextBox@sgg@@QEAA@VVector2@Vectormath@@@Z");

    vector8x8_push = GetSymbolAddress(
        "?push_back@?$vector@PEAUPipeline@@Vallocator_forge@eastl@@@eastl@@QEAAXAEBQEAUPipeline@@@Z");

    GUIComponentReflectionHelper_ReflectComponent_GUIComponentButton =
        GetSymbolAddress("sgg::GUIComponentReflectionHelper::ReflectComponent<sgg::GUIComponentButton *>");
    GUIComponentReflectionHelper_ReflectComponent_GUIComponentTextBox =
        GetSymbolAddress("sgg::GUIComponentReflectionHelper::ReflectComponent<sgg::GUIComponentTextBox *>");

    ScreenManager_AddScreen_screen = GetSymbolAddress("?AddScreen@ScreenManager@sgg@@QEAAXPEAVGameScreen@2@@Z");

    ScreenData_ReadXml = GetSymbolAddress("sgg::ScreenData::ReadXml");
}
#endif //  HADES2_MOD_LOADER
