//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#define SGG_OFFSET_TO(type, offset) reinterpret_cast<type *>(reinterpret_cast<uintptr_t>(this) + offset);

#define SGG_OFFSET_TO_SET(offset, value)                                                                               \
    decltype(value) *ptr = SGG_OFFSET_TO(decltype(value), offset);                                                     \
    *ptr = value