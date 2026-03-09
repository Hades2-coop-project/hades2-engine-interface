//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class GUIComponent;

class IGUIComponentContainer {
  public:
    virtual GUIComponent GetComponent(const eastl::basic_string<char, eastl::allocator_forge> *) = 0;
    virtual ~IGUIComponentContainer() = 0;
};
static_assert(sizeof(IGUIComponentContainer) == 0x8, "Incorrect sgg::IGUIComponentContainer size");
} // namespace sgg