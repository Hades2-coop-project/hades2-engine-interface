//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "Entity.h"

namespace sgg {

template <typename T> class EntityLinkedObject {
    T *mObject;
    Entity mEntity;
};

static_assert(sizeof(EntityLinkedObject<void>) == 0x8 + sizeof(Entity), "Incorrect sgg::EntityLinkedObject size");
} // namespace sgg