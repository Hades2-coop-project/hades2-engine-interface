//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HashGuid.h"
#include "HookTable.h"
#include "UnitData.h"
#include "AnimationData.h"

namespace sgg {

class GameDataManager {

  public:
    static UnitData *GetUnitData(HashGuid name) {
        return ((UnitData * (__fastcall *)(HashGuid)) HookTable::Instance().GameDataManager_GetUnitData)(name);
        ;
    };

    static AnimationData *GetAnimationData(HashGuid name) {
        return ((AnimationData * (__fastcall *)(HashGuid)) HookTable::Instance().GameDataManager_GetAnimationData)(name);
        ;
    };

};
} // namespace sgg