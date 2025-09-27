//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HookTable.h"
#include <lua.hpp>

namespace sgg {

class ScriptManager
{
  public:
    static bool Load(const char* sciptPath)
    {
        return ((bool(__fastcall *)(const char *))HookTable::Instance().ScriptManager_Load)(sciptPath);
    }

    static lua_State *GetLuaState() { return *(lua_State **)HookTable::Instance().ScriptManager_LuaState; }
};

}