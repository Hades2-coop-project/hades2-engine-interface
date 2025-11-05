//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Thing.h"

#include <cstdint>

#include "IRectangle.h"
#include "ObstacleData.h"
#include "Handle.h"
#include "TransitionHelper.h"
#include "../libs/EASTL-forge1.51/vector.h"

namespace sgg {
class Animation;

__declspec(align(16)) class Obstacle : public Thing {
  public:
    unsigned int mFlags;
    unsigned int mGridSets;
    int mScreenEdgeTargetId;
    IRectangle mDrawBounds;
    Animation *mOcclusionFootprintAnim;
    ObstacleData mData;
    TransitionHelper<float> mMoverX;
    TransitionHelper<float> mMoverY;
    Handle<Obstacle> mParent;
    Handle<Obstacle> mHandle;
    unsigned int mSortIndex;
    eastl::vector<Handle<Obstacle>, eastl::allocator_forge> mChildren;
};
static_assert(sizeof(Obstacle) == 0x7C0, "Incorrect sgg::Obstacle size");
} // namespace sgg
