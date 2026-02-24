//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HookTable.h"
#include "helpers.h"

namespace sgg {
class MenuScreen;

class ScreenData {
  public:
    // This fucntion reads json
    void ReadXml(MenuScreen *menuScreen, const char *path) {
        GET_HOOK(ScreenData_ReadXml, void(__fastcall *)(void *, void *, const char *))(this, menuScreen, path);
    }

  private:
    char mDef[0xF0];
};

static_assert(sizeof(ScreenData) == 0xF0, "Incorrect sgg::ScreenData size");
} // namespace sgg
