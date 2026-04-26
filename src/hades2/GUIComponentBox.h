//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "GUIComponent.h"

namespace sgg {
class GUIComponentBox : public GUIComponent {
  protected:
    Color mBorderColor;
    Color mBackColor;
    bool mFill;
    int mBorderSize;
};

static_assert(sizeof(GUIComponentBox) == 0x550, "Incorrect GUIComponentBox size");
} // namespace sgg
