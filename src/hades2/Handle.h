//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {

template <typename T> class Handle {
    unsigned int mId;
};
static_assert(sizeof(Handle<void>) == 0x4, "Incorrect sgg::Handle size");
} // namespace sgg
