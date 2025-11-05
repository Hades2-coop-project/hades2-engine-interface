//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class lua_State;

// The class is not used in sgg namespace itself, but it's part of the engine interface.
class LuaTable {
  public:
    lua_State *mLuaState;
    int mTableRef;
};

static_assert(sizeof(LuaTable) == 0x10, "Incorrect sgg::LuaTable size");
} // namespace sgg
