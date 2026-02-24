//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class GUIFlasher {
  public:

  private:
    char pad[0x30];
};
static_assert(sizeof(GUIFlasher) == 0x30, "Incorrect sgg::GUIFlasher size");
} // namespace sgg