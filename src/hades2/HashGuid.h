//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once
#include "HookTable.h"

namespace sgg {
class HashGuid {
  public:
    HashGuid(uint32_t id) : mId(id) {};
    uint32_t GetId() const noexcept { return mId; };

    static HashGuid StringIntern(const char *str, size_t size) {
        return ((HashGuid(__fastcall *)(const char*, size_t))HookTable::Instance().HashGuid_StringIntern)(
            str, size);
    }

  private:
    uint32_t mId;
};
} // namespace sgg