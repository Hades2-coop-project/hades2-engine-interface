//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class IRectangle {
    int x, y, w, h;
};
static_assert(sizeof(IRectangle) == 0x10, "Incorrect sgg::IRectangle size");
}
