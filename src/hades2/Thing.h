//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "MapThing.h"
#include "IRenderComponent.h"
#include "IRectangle.h"
#include "EntityLinkedObject.h"
#include "LuaTable.h"

namespace sgg {
class ThingData;
class BodyComponent;
class LifeComponent;
class PhysicsComponent;
class VacuumComponent;
class MagnetismComponent;
class LightOccluderComponent;
class TranslateComponent;
class PlayerNearbyComponent;
class FlashComponent;
class ShakeComponent;
class TextComponent;
class SpeechComponent;
class Interact;
class Animation;

__declspec(align(8)) class Thing : public IRenderComponent {
  public:
    MapThing *GetMapThing() const noexcept {
        return *reinterpret_cast<MapThing **>(reinterpret_cast<uint64_t>(this) + 0x520);
    };

    void SetVisible(bool visible) noexcept { mVisible = visible; };

    Vectormath::Vector2 GetLocation() const noexcept { return mLocation; };
    uint32_t GetId() const noexcept { return mId; };
    HashGuid GetName() const noexcept { return mName; };
    LuaTable &GetLuaTable() noexcept { return mAttachedLua; };

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
    IRectangle mRectangle;
    Vectormath::Vector3 mDirection;
    ThingData *pThingData;
    BodyComponent *pBody;
    LifeComponent *pLife;
    PhysicsComponent *pPhysics;
    VacuumComponent *pVacuum;
    MagnetismComponent *pMagnetism;
    LightOccluderComponent *pOccluder;
    TranslateComponent *pTranslate;
    PlayerNearbyComponent *pPlayerNearby;
    FlashComponent *pFlash;
    ShakeComponent *pShake;
    TextComponent *pText;
    SpeechComponent *pSpeech;
    Interact *pInteraction;
    Animation *pAnim;
    EntityLinkedObject<sgg::Thing> mAttachedTo;
    LuaTable mAttachedLua;

    uint8_t __pad_to_finish[1296];
};
static_assert(sizeof(Thing) == 0x650, "Incorrect sgg::Thing size");
} // namespace sgg
