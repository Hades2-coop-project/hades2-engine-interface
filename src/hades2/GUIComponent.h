//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Vector2.h"
#include "Color.h"
#include "GuiComponentType.h"
#include "ComponentData.h"
#include "GUIAction.h"
#include "GUIFlasher.h"
#include "Thing.h"
#include "LuaFunction.h"
#include "ComponentAction.h"

namespace sgg {
class IRectangle;
class IGUIComponentContainer;
class ComponentData;
class InputHandler;
class Localization;

namespace EControllerIndex {
enum class Enum : uint32_t;
}

class GUIComponent {
  public:
    virtual bool ShouldDraw() = 0;
    virtual void Clear() = 0;
    virtual bool HasText() = 0;
    virtual void Draw() = 0;
    virtual bool IsGraphicVisible() = 0;
    virtual bool IsPhysicallyVisible() = 0;
    virtual void UseDefaultScale() = 0;
    virtual float GetDrawScale() = 0;
    virtual void DefaultFlash() = 0;
    virtual void FlashInMenu() = 0;
    virtual void StopFlashing() = 0;
    virtual void OnMouseOver() = 0;
    virtual void OnMouseOff() = 0;
    virtual void PostActivated() = 0;
    virtual bool IsUnderCursor() = 0;
    virtual void Disable() = 0;
    virtual bool IsUseable() = 0;
    virtual void OnUnselected() = 0;
    virtual void PreHotLoad() = 0;
    virtual IRectangle *GetArea(IRectangle *result) = 0;
    virtual IRectangle *GetScreenArea(IRectangle *result) = 0;
    virtual void Load(const ComponentData *) = 0;
    virtual void OnSelected(GUIComponent *) = 0;
    virtual void Update(float) = 0;
    virtual void OnKeyPress(InputHandler *) = 0;
    virtual bool OnButtonPress(InputHandler *) = 0;
    virtual void OnMouseButtonPress(InputHandler *) = 0;
    virtual bool Contains(Vectormath::Vector2) = 0;
    virtual void SetParent(IGUIComponentContainer *) = 0;
    virtual void ApplyDataToName(const eastl::basic_string<char, eastl::allocator_forge> *,
                                 const ComponentData *) = 0;
    virtual bool HandleInput(InputHandler *, float) = 0;
    virtual bool ScreenContains(Vectormath::Vector2) = 0;
    virtual bool OnClicked(Vectormath::Vector2) = 0;
    virtual void NotifyComponentsOfClick(Vectormath::Vector2) = 0;
    virtual void OnFocusOn() = 0;
    virtual void OnFocusOff() = 0;
    virtual eastl::basic_string<char, eastl::allocator_forge> *
    ToString(eastl::basic_string<char, eastl::allocator_forge> *result) = 0;
    virtual void UseDefaultText() = 0;
    virtual void ReReadText() = 0;
    virtual void SetFont(HashGuid) = 0;
    virtual void SetText(const char *) = 0;
    virtual void SetColor(Color) = 0;
    virtual void SetColors(Color, Color) = 0;
    virtual EGuiComponentType GetComponentType() = 0;
    virtual void SetTextColor(Color) = 0;
    virtual void SetScale(float) = 0;
    virtual void ModifyScale(float) = 0;
    virtual bool IsSelectable() = 0;
    virtual void SetLocation(Vectormath::Vector2) = 0;
    virtual ~GUIComponent() = 0;

    Vectormath::Vector2 GetLocation() const noexcept { return mLocation; };
    ComponentData &GetComponentData() noexcept { return mData; };
    const ComponentData &GetComponentData() const noexcept { return mData; };

    GUIAction &GetActivateAction() noexcept { return mOnActivated; };

    void SetFadeOpacity(float opacity) { mFadeOpacity = opacity; }
    void SetFadeDelay(float delay) { mFadeDelay = delay; }
    void SetFadeTarget(float target) { mFadeTarget = target; }

  private:
    int mMouseOverSoundId;
    bool mHidden;
    bool mUseable;
    Vectormath::Vector2 mLocation;
    GUIFlasher *mSimpleFlasher;
    const Color NO_COLOR;
    bool mFirstSetupDone;
    bool mBlockSetup;
    bool mUseWorldLocation;
    bool mIsUseable;
    bool mCanBeFocused;
    float mScaleTarget;
    float mScaleModifier;
    float mAngle;
    float mScale;
    float mFadeOpacity;
    float mFadeDelay;
    float mFadeTarget;
    int mCustomWidth;
    int mCustomHeight;
    float mFadeOutDelay;
    float mFadeInDelay;
    float mMoveFraction;
    Vectormath::Vector2 mOriginalLocation;
    Vectormath::Vector2 mMoveTarget;
    Vectormath::Vector2 mMoveStart;
    Color mColors;
    Color mColorTarget;
    Localization *mLoc;
    ComponentData mData;
    GUIFlasher mFlasher;
    IGUIComponentContainer *mParentContainer;
    GUIComponent *mParent;
    bool mPulse;
    float mRotationSpeed;
    Action mOnClick;
    Action mOnSelected;
    Action mOnActivated;
    Action mOnUnselected;
    Action mOnActivatedAlt;
    ComponentAction mMouseOnAction;
    ComponentAction mMouseOffAction;
    ComponentAction mSelfOnSelected;
    ComponentAction mSelfOnActivated;
    bool mBlocksInput;
    bool mBlockTooltip;
    eastl::basic_string<char, eastl::allocator_forge> mName;
    eastl::basic_string<char, eastl::allocator_forge> mDataValue;
    eastl::basic_string<char, eastl::allocator_forge> mTooltipId;
    eastl::basic_string<char, eastl::allocator_forge> mTextBoxTooltipId;
    Vectormath::Vector2 mTooltipLocation;
    LuaTable mLuaData;
    LuaFunction mActivateFunction;
    Thing *mAttachedTo;
    GUIComponent *mAttachedToComponent;
    Vectormath::Vector2 mAttachOffset;
    bool mSkipNormalDraw;
    bool mSkipDraw;
    int mFastForwardWeight;
    bool mIsShell;
    unsigned __int64 mId;
};

static_assert(sizeof(GUIComponent) == 0x550, "Incorrect GUIComponent size");
} // namespace sgg
