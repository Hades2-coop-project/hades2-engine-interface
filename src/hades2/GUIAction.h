//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Action.h"

namespace sgg {
typedef Action GUIAction;

static_assert(sizeof(GUIAction) == 0x18, "Incorrect sgg::GUIAction size");
} // namespace sgg
