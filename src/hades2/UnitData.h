//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "UnitDataDef.h"
#include "GameData.h"

namespace sgg {
class UnitData : public GameData {
  public:
    UnitDataDef *GetDef() noexcept { return &mDef; };

  private:
    UnitDataDef mDef;
};

static_assert(sizeof(UnitData) == 0xA0, "Incorrect sgg::UnitData size");
} // namespace sgg