//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "MenuScreen.h"
#include "GUIComponentButton.h"
#include "HookTable.h"

namespace sgg {
class MainMenuScreen : public MenuScreen {
  public:
    GUIComponentButton *GetPlayGameButton() const noexcept { return mPlayGameButton; };
    GUIComponentButton *GetExitButton() const noexcept { return mExitButton; };

    void OpenProfiles() { GET_HOOK(MainMenuScreen_OpenProfiles, void(__fastcall *)(void *))(this); }

  private:
    bool mPressStartMode;
    bool mPressStartAwaitingInput;
    bool mNeedsApplyUserSettings;
    sgg::GUIComponentAnimation *mLogo;
    sgg::GUIComponentAnimation *mCharacter;
    sgg::GUIComponentAnimation *mUpdateTitleBacking;
    sgg::GUIComponentAnimation *mNewAnnouncementTag;
    sgg::GUIComponentButton *mPlayGameButton;
    sgg::GUIComponentButton *mCloudSaveButton;
    sgg::GUIComponentButton *mSettingsButton;
    sgg::GUIComponentButton *mAnnouncementButton;
    sgg::GUIComponentButton *mExitButton;
    sgg::GUIComponentTextBox *mLastUpdateText;
    sgg::GUIComponentTextBox *mUpdateTitleText;
    sgg::GUIComponentTextBox *mControllerWarningText;
    sgg::GUIComponentTextBox *mGraphicsDriverWarningText;
    sgg::GUIComponentTextBox *mNextUpdateBaseFormat;
    sgg::GUIComponentTextBox *mNextUpdateCountFormat;
    sgg::GUIComponentButton *mFeedbackButton;
    sgg::GUIComponentButton *mWebsiteButton;
    sgg::GUIComponentButton *mSoundtrackButton;
    sgg::GUIComponentButton *mStoreButton;
    sgg::GUIComponentButton *mMailingListButton;
    sgg::GUIComponentButton *mNextUpdateButton;
    sgg::GUIComponentTextBox *mNextUpdateText;
    sgg::GUIComponentButton *mXboxChangeProfileButton;
    sgg::GUIComponentButton *mXboxPressStartButton;
    sgg::GUIComponentTextBox *mXboxGamertagLabel;
    sgg::GUIComponentBox *mFront;
    sgg::GUIComponentButton *mSubscreenOpenButton;
    bool mScreenCovered;
};
#ifdef HADES2_DEBUG_VERSION
static_assert(sizeof(MainMenuScreen) == 0x3A8, "Incorrect sgg::MainMenuScreen size");
#else
static_assert(sizeof(MainMenuScreen) == 0x390, "Incorrect sgg::MainMenuScreen size");
#endif
} // namespace sgg
