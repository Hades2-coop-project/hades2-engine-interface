//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {

class TextureHandle {
    unsigned int id;
};

static_assert(sizeof(TextureHandle) == 0x4, "Incorrect sgg::TextureHandle size");
} // namespace sgg
