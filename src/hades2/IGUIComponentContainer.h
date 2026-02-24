//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class IGUIComponentContainer {
  public:

  private:
    void *vtbl;
};
static_assert(sizeof(IGUIComponentContainer) == 0x8, "Incorrect sgg::IGUIComponentContainer size");
} // namespace sgg