//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Vector2.h"
#include "TimeSpan.h"
#include "ScreenManager.h"

#include "../EASTL-forge1.51/EABase/eabase.h"
#include "../EASTL-forge1.51/vector.h"

namespace sgg {
class InputHandler;
enum class ScreenState : uint32_t;

enum class ScreenType : uint32_t {
};

class GameScreen {
  public:
    virtual void OnExit();
    virtual void LoadContent();
    virtual void UnloadContent();
    virtual void Update(float, const eastl::vector<InputHandler *, eastl::allocator_forge> *);
    virtual bool HandleInput(InputHandler *, float);
    virtual void HandleNoInput();
    virtual void Draw();
    virtual void ExitScreen();
    virtual void Clear();
    virtual void Init(ScreenManager *);
    virtual ScreenType GetType();
    virtual ~GameScreen();

    ScreenManager *GetScreenManager() const noexcept { return mScreenManager; }

    void SetLoverInputBlock(bool status) noexcept { mBlockLowerInput = status; }
    void SetAllowDuplicates(bool allowed) noexcept { mAllowDuplicates = allowed; }

protected:
    bool mTransitionFinished;
    TimeSpan Zero;
    Vectormath::Vector2 mDrawLocation;
    uint8_t mFullscreenSpriteEffect;
    bool mRemoved;
    bool mIsVisible;
    bool mUseFadeTransition;
    bool mBlockLowerInput;
    bool mOverPauseMenu;
    bool mAllowDuplicates;
    bool mBlockContentUnload;
    TimeSpan mTransitionOnTime;
    TimeSpan mTransitionOffTime;
    float mTransitionPosition;
    ScreenState mScreenState;
    bool mIsExiting;
    ScreenManager *mScreenManager;

};
static_assert(sizeof(GameScreen) == 0x50, "Incorrect sgg::GameScreen size");
} // namespace sgg