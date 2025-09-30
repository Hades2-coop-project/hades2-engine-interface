//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class UnitDataDef {
    uint8_t pad[0x88];
};
static_assert(sizeof(UnitDataDef) == 0x88, "Incorrect sgg::UnitDataDef size");
} // namespace sgg