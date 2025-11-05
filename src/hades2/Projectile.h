//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Thing.h"

namespace sgg {
class Projectile : public Thing {
  public:
    int GetOwnerId() const noexcept { return mOwnerId; };

  private:
    bool mHitMaxRange;
    bool mHasStarted;
    bool mUseStartMarker;
    bool mForceOwnerReturn;
    bool mDetonated;
    bool mBlockSpawns;
    bool mBlinkWeaponActive;
    bool mTriggerFireEndOnDeath;
    bool mExcludeFromCap;
    uint8_t pad1[3]; // padding bytes
    float mDamageMultiplier;
    int mOwnerId;
    uint8_t pad2[1160]; // padding bytes
};
static_assert(sizeof(sgg::Projectile) == 0xAF0, "sgg::Projectile has invalid size");
}