//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include <../libs/EASTL-forge1.51/functional.h>

namespace sgg {
template <typename T> class TransitionHelper {
    float mEaseIn;
    float mEaseOut;
    float mTimeModifierFraction;
    //eastl::function<void __cdecl(void)> mOnUpdate;
    uint8_t pad[36]; // function + 4 padding bytes
    
    bool mInitialized;
    bool mPingPong;
    bool mAngleValues;
    bool mSmoothStep;
    float mStartValue;
    float mEndValue;
    float mDuration;
    float mTimeRemaining;
    float mFraction;
    float mPhaseOffset;
    uint8_t pad2[4];
};
static_assert(sizeof(TransitionHelper<float>) == 0x50, "Incorrect sgg::TransitionHelper size");
} // namespace sgg
