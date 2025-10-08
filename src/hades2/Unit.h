//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Thing.h"

namespace sgg {
class UnitData;
class Player;

__declspec(align(16)) class Unit : public Thing {

public:
    void Delete() { ((void(__fastcall *)(void *))HookTable::Instance().Unit_Delete)(this); }
    UnitData *GetData() const noexcept { return pData; };

    void SetPlayer(Player *player) { pPlayer = player; };

private:
    bool mAllowDodge;

    Player *pPlayer;
    bool mAllowInput;
    bool mIsMoving;
    bool mIsMovingTo;
    bool mHasActivated;
    bool mAllowAnyFire;
    bool padding0;

    UnitData *pData;
    uint8_t pad[432];
};

static_assert(sizeof(Unit) == 0x820, "Incorrect sgg::Unit size");
} // namespace sgg