//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "../EASTL-forge1.51/vector.h"

namespace sgg {
class GUIComponent;

class ComponentAction {
  public:
    eastl::vector<eastl::function<void __cdecl(sgg::GUIComponent *)>, eastl::allocator_forge> mCallBacks;
};
static_assert(sizeof(ComponentAction) == 0x18, "Incorrect sgg::ComponentAction size");
} // namespace sgg