//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Vector2.h"
#include "MapThing.h"
#include "IRenderComponent.h"

namespace sgg {
__declspec(align(8)) class Thing : public IRenderComponent {
  public:
    MapThing *GetMapThing() const noexcept {
        return *reinterpret_cast<MapThing **>(reinterpret_cast<uint64_t>(this) + 0x520);
    };

    void SetVisible(bool visible) noexcept { mVisible = visible; };

    Vectormath::Vector2 GetLocation() const noexcept { return mLocation; };
    uint32_t GetId() const noexcept { return mId; };
    HashGuid GetName() const noexcept { return mName; };

  private:
    bool mVisible;
    bool mAnimFreeze;
    bool mSuppressSounds;
    bool mIsDisposed;
    bool mCanBeManagedByDrawGrid;
    // pad
    uint32_t mId;
    HashGuid mName;
    float mAttachOffsetZ;
    float mZLocation;
    float mTallness;
    float mTimeModifierFraction;
    float mElapsedTimeMultiplier;
    float mSpawnTime;
    Vectormath::Vector2 mLocation;
    Vectormath::Vector2 mSpawnLocation;

    uint8_t __pad_to_finish[1480];
};
static_assert(sizeof(Thing) == 0x640, "Incorrect sgg::Thing size");
} // namespace sgg
