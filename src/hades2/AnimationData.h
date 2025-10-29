//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "GameData.h"

namespace sgg {
class AnimationData : public GameData {
  public:
  private:
    uint8_t pad[0x498 - sizeof(GameData)];
};

static_assert(sizeof(AnimationData) == 0x498, "Incorrect sgg::AnimationData size");
} // namespace sgg
