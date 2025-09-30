//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "../../libs/EASTL-forge1.51/vector.h"
#include "../HookTable.h"
#include "InputHandler.h"
#include "Player.h"
#include "allocator.h"

namespace sgg {

class PlayerManager {
    friend class PlayerManagerExtension;

  public:
    static PlayerManager *Instance() {
        return ((PlayerManager * (__fastcall *)()) HookTable::Instance().PlayerManager_Instance)();
    }

    sgg::Player *AddPlayer(uint64_t index) {
        return ((sgg::Player * (__fastcall *)(void *, uint64_t)) HookTable::Instance().PlayerManager_AddPlayer)(this,
                                                                                                                index);
    }

    void AssignController(sgg::Player *player, uint32_t index) {
        ((void(__fastcall *)(void *, sgg::Player *, uint32_t))HookTable::Instance().PlayerManager_AssignController)(
            this, player, index);
    }

    sgg::Player *GetPlayer(uint64_t index) const noexcept { return m_palyers[index]; }

  private:
    eastl::vector<sgg::InputHandler *, eastl::allocator_forge> m_inputMethods;
    eastl::vector<sgg::Player *, eastl::allocator_forge> m_palyers;
};
static_assert(sizeof(PlayerManager) == 0x30, "Incorrect PlayerManager size");

} // namespace sgg
