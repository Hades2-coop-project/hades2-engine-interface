//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class ObstacleData {
    uint8_t pad[0x78]; // mDef
};
static_assert(sizeof(ObstacleData) == 0x78, "Incorrect sgg::ObstacleData size");
} // namespace sgg
