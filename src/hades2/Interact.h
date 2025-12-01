//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HookTable.h"

namespace sgg {
class Unit;
class Thing;
class InteractData;

class Interact {

  public:
    void Use(Unit *user, bool unk1, bool unk2) noexcept {
        ((void(__fastcall *)(void *, Unit *, bool, bool))HookTable::Instance().Interact_Use)(this, user, unk1, unk2);
    };

  private:
    int mLastUseFrame;
    float mRepeatTimer;
    bool mLastUseWasRepeat;
    Thing *pOwner;
    InteractData *pData;
    bool mHasBeenUsed;
    bool mShouldReleaseData;
    bool mEnabled;
};
static_assert(sizeof(Interact) == 0x28, "Incorrect SGG::Iteract size");
} // namespace SGG
