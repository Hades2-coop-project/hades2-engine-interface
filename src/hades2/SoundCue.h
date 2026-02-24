//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HashGuid.h"

namespace sgg {
class AudioChannel;

class SoundCue {
    AudioChannel *pOwner;
    HashGuid mName;
};

static_assert(sizeof(SoundCue) == 0x10, "Incorrect sgg::SoundCue size");
}
