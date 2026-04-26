//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "GUIComponent.h"
#include "HookTable.h"
#include "TextureHandle.h"
#include <cstdint>

namespace sgg {
class RemappableControl;
class GUIComponentAnimation;
class GUIComponentTextBox;
class MenuScreen;

enum class KeyboardButtonId : uint32_t {};
enum class GamepadButtonId : uint32_t {};
enum class MouseButtonId : uint32_t {};
enum class SelectionTextureType : uint32_t { REPLACE = 0, OVERLAY = 0x1, UNDERLAY = 0x2 };

class GUIComponentButton : public GUIComponent {
  public:
    void UseDefaultText() {
        reinterpret_cast<void (*)(void *)>(HookTable::Instance().GUIComponentButton_UseDefaultText)(this);
    }

  private:
    RemappableControl *mControl;
    KeyboardButtonId mHotkey;
    GamepadButtonId mGamepadButton;
    bool mHasGamepadButton;
    bool mSelectable;
    Vectormath::Vector2 mTextOffset;
    Color mButtonColor;
    bool mForceSelected;
    TextureHandle mSelectedTexture;
    TextureHandle mUnderMouseTexture;
    HashGuid GraphicName;
    GUIComponentAnimation *mAnim;
    GUIComponentAnimation *mSelectedAnim;
    GUIComponentTextBox *mTextBox;
    float mOverlayTextureOffsetY;
    TextureHandle mNormalTexture;
    TextureHandle mBackTexture;
    TextureHandle mOverlayTexture;
    MouseButtonId mMouseHotkey;
    SelectionTextureType mSelectionDisplayType;
    MenuScreen *mOwner;
    bool mFadeSelectionTexture;
};
static_assert(sizeof(GUIComponentButton) == 0x5B0, "Incorrect GUIComponentButton size");
} // namespace sgg
