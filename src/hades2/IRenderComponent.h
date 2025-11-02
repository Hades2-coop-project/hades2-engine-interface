//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Rtti.h"
#include "Entity.h"

namespace sgg {
class IRenderComponent: public Rtti {
  public:
    sgg::Entity GetEntity() const noexcept { return mEntity; };

private:
    uint64_t mSortScore;  // sgg::SortScore
    uint8_t mSortMode; // sgg::SortMode
    uint32_t mSecondarySortKey;
    bool mHasOutline;
    sgg::Entity mEntity;
    uint8_t booundsPad[0x18]; // sgg::Bounds
};
static_assert(sizeof(IRenderComponent) == 0x40, "Incorrect sgg::IRenderComponent size");
} // namespace sgg