//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Vector2.h"

namespace sgg {
struct GamePadHandler {
    uint8_t mControllerIndex;
    uint32_t Directions;
    uint32_t PrevDirections;
};
static_assert(sizeof(GamePadHandler) == 0xC, "Incorrect sgg::GamePadHandler size");

class InputHandler {
  public:
    uint8_t GetGamepadId() const noexcept { return _gamePadHandler.mControllerIndex; };
    void SetGamepadId(uint8_t index) noexcept { _gamePadHandler.mControllerIndex = index; };

  private:
    Vectormath::Vector2 _prevSearchDirection;
    uint8_t _keyboardHandler; // sgg::KeyboardHandler
    uint8_t _mouseHandler;    // sgg::MouseHandler
    uint8_t pad[2];
    GamePadHandler _gamePadHandler;
    float _repeatDelay;

    uint8_t pad_end[0x64];
};

static_assert(sizeof(InputHandler) == 0x80, "Incorrect sgg::InputHandler size");
} // namespace sgg