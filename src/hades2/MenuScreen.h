//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "../EASTL-forge1.51/hash_map.h"
#include "../EASTL-forge1.51/string.h"
#include "../EASTL-forge1.51/vector.h"
#include "GUIComponentReflectionHelper.h"
#include "GameScreen.h"
#include "HookTable.h"
#include "IGUIComponentContainer.h"
#include "IRectangle.h"
#include "Rectangle.h"
#include "ScreenData.h"
#include "GUIComponent.h"
#include "GUIComponentTextBox.h"
#include "GUIComponentButton.h"

constexpr size_t INVALID_COMPONENT_POS = -1;

namespace sgg {

class GUIComponentAnimation;
class GUIComponentBox;
class GUIComponentImage;
class InputHandler;

class MenuScreen : public GameScreen, public IGUIComponentContainer {
  public:
    virtual void OnExit() = 0;
    virtual void LoadContent() = 0;
    virtual void UnloadContent() = 0;
    virtual void Update(float deltaTime,
                        const eastl::vector<InputHandler *, eastl::allocator_forge> *inputHandlers) = 0;
    virtual bool HandleInput(InputHandler *input, float deltaTime) = 0;
    virtual void HandleNoInput() = 0;
    virtual void Draw(float deltaTime) = 0;
    virtual void ExitScreen() = 0;
    virtual void Clear() = 0;
    virtual void Init(ScreenManager *manager) = 0;
    virtual ScreenType GetType() = 0;
    virtual ~MenuScreen() = 0;
    virtual bool FreeFormSelect(InputHandler *input, float deltaTime) = 0;
    virtual void OnCancel() = 0;
    virtual bool WasClickPressed(InputHandler *input) = 0;
    virtual void SelectComponent(GUIComponent *component, InputHandler *input) = 0;
    virtual bool NotifyComponentsOfClick(Vectormath::Vector2 position) = 0;
    virtual bool ValidateCursorLocation(InputHandler *input) = 0;
    virtual void PostLoad() = 0;
    virtual void OnLanguageChanged() = 0;
    virtual void OnResolutionChanged(float oldWidth, float oldHeight) = 0;
    virtual void RestoreDefaults() = 0;
    virtual void Load(const char *filename) = 0;
    virtual GUIComponent *GetFirstUseableComponent() = 0;
    virtual bool TryExitScreen() = 0;
    virtual void Scroll(float amount, bool vertical) = 0;

    void CreateBack(float oppacity) {
        reinterpret_cast<void(__fastcall *)(void *, float)>(HookTable::Instance().MenuScreen_CreateBack)(this,
                                                                                                         oppacity);
    }

    void CreateBackground(eastl::basic_string<char, eastl::allocator_forge> * textureName) {
        reinterpret_cast<void(__fastcall *)(void *, void*)>(HookTable::Instance().MenuScreen_CreateBackground)(this, textureName);
    }

    void CreateTitleText(MenuScreen *component) {
        reinterpret_cast<void(__fastcall *)(void *, MenuScreen *)>(HookTable::Instance().MenuScreen_CreateTitleText)(
            this, component);
    }

    void CreateCancelButton(MenuScreen* component) {
        reinterpret_cast<void(__fastcall *)(void *, MenuScreen *)>(HookTable::Instance().MenuScreen_CreateCancelButton)(
            this, component);
    }

    void AddComponent(GUIComponent *component) {
        reinterpret_cast<void(__fastcall *)(void *, GUIComponent **)>(HookTable::Instance().vector8x8_push)(
            &mComponents, &component);
    }

    void MoveComponentComponentBack(GUIComponent *component, size_t up) {
        size_t pos = GetComponentPosition(component);
        if (pos == INVALID_COMPONENT_POS)
            return;

        const size_t targetPos = pos - up;
        for (size_t i = pos - 1; up > 0; i--, up--) {
            mComponents[i + 1] = mComponents[i];
        }
        mComponents[targetPos] = component;
    }

    size_t GetComponentPosition(GUIComponent *component) const noexcept {
        for (size_t i = 0; i < mComponents.size(); i++) {
            if (component == mComponents[i])
                return i;
        }
        return INVALID_COMPONENT_POS;
    }

    ScreenData &GetScreenData() noexcept { return mData; };

    GUIComponentReflectionHelper &GetReflectionHelper() { return mReflectionHelper; }

    GUIComponentButton *GetCancelButton() const noexcept { return mCancelButton; };

  private:
    struct InsertCommand {
        GUIComponent *mToInsert;
        GUIComponent *mLocation;
        bool mIsBefore;
    };
    static_assert(sizeof(InsertCommand) == 0x18, "Size of MenuScreen is not 0x4B0");

  protected:
    eastl::vector<sgg::GUIComponent *, eastl::allocator_forge> mPossibleClicks;
    eastl::vector<sgg::GUIComponent *, eastl::allocator_forge> mMouseOverChoices;
    eastl::vector<Vectormath::Vector3, eastl::allocator_forge> mLastTestLocations;
    const Vectormath::Vector2 mZero;
    const sgg::IRectangle mIEmptyRect;
    const sgg::Rectangle mEmptyRect;
    bool mLoadDefaultComponents;
    bool mPrevGamepadCursorControl;
    sgg::MenuScreen *mCombinedFreeFormSelect;
    sgg::GUIComponent *mMouseOverComponent;
    eastl::vector<sgg::GUIComponent *, eastl::allocator_forge> mComponents;
    Vectormath::Vector2 mLocation;
    Vectormath::Vector2 mSize;
    sgg::GUIComponentReflectionHelper mReflectionHelper;
    bool mAllowInteractUnder;
    long double mOpenTime;
    Vectormath::Vector2 mPrevSearchDirection;
    float mRepeatDelay;
    float mInteractDelay;
    eastl::basic_string<char, eastl::allocator_forge> mDataPath;
    sgg::GUIComponentBox *mBack;
    sgg::GUIComponentImage *mBackground;
    sgg::GUIComponentAnimation *mAnimatedBackground;
    sgg::GUIComponentTextBox *mTitleText;
    sgg::GUIComponentTextBox *mSpoiler;
    sgg::GUIComponentAnimation *mPressTopAnimation;
    sgg::GUIComponentButton *mConfirmButton;
    sgg::GUIComponentButton *mCancelButton;
    sgg::GUIComponent *mSelectedComponent;
    sgg::ScreenData mData;
};
static_assert(sizeof(MenuScreen) == 0x2C0, "Size of MenuScreen is not 0x4B0");
} // namespace sgg