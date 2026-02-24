//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "GUIComponentBox.h"

namespace sgg {

class GUIComponentTextBox : public GUIComponentBox {
  private:
    char pad[0x1A0];
};
static_assert(sizeof(GUIComponentTextBox) == 0x700, "Incorrect sgg::GUIComponentTextBox size");
} // namespace sgg
