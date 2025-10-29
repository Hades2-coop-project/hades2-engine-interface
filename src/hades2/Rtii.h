//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include <cstdint>

namespace sgg {
enum class RtiiType : uint32_t {
    Component = 0x1,
    Weapon = 0x2,
    GameEvent = 0x4,
    IUndoRedoRecord = 0x8,
    Thing = 0x11,
    Animation = 0x21,
    Light = 0x41,
    Obstacle = 0x91,
    Unit = 0x111,
    Projectile = 0x211,
    ArcProjectile = 0x611,
    BeamProjectile = 0xA11,
    HomingProjectile = 0x1211,
    InstantProjectile = 0x2211,
    LobProjectile = 0x4211,
    BookAnimation = 0x8021,
    SlideAnimation = 0x18021,
    ConstantAnimation = 0x20021,
    DatalessAnimation = 0x40021,
    ModelAnimation = 0x80021,
    PlayerUnit = 0x200111,
    BlinkWeapon = 0x22,
    GunWeapon = 0x42,
    RamWeapon = 0x82,
    DelayedGameEvent = 0x24,
    ScriptUpdateGameEvent = 0x44,
    UpdateGameEvent = 0x84,
    PersistentGameEvent = 0x104,
    UndoTransaction = 0x28,
    UndoRedoRecord = 0x48,
};

class Rtii {
  public:
    bool IsPlayerUnit() const noexcept { return mType == RtiiType::PlayerUnit; }

  private:
    void *vftable;
    RtiiType mType;
};
static_assert(sizeof(Rtii) == 0x10, "Incorrect sgg::Rtii size");
} // namespace sgg
