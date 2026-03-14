//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HookTable.h"

class lua_State;
typedef int (*lua_CFunction)(lua_State *L);

namespace HookedLua {
static lua_State* GetLuaState() { return *reinterpret_cast<lua_State **>(HookTable::Instance().luaState); }

static int lua_pcallk(lua_State *L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k) {
    return GET_HOOK(lua_pcallk, int (__fastcall*)(lua_State *, int, int, int, int, lua_CFunction))(L, nargs, nresults, errfunc, ctx, k);
}

static int luaL_loadbufferx(lua_State *L, const char* buffer, size_t size, const char* name, const char* mode) {
    return GET_HOOK(luaL_loadbufferx, int (__fastcall*)(lua_State *L, const char* buffer, size_t size, const char* name, const char* mode))(L, buffer, size, name, mode);
};

static int luaL_getsubtable(lua_State *L, int idx, const char *fname) {
    return GET_HOOK(luaL_getsubtable, int (__fastcall*)(lua_State *L, int idx, const char *fname))(L, idx, fname);
};

static void lua_rawseti(lua_State* L, int idx, int n) {
    GET_HOOK(lua_rawseti, int(__fastcall *)(lua_State *, int, int))(L, idx, n);
}
}
