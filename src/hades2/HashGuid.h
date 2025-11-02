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
    const char *c_str() const {
        return ((const char* (__fastcall *)(const HashGuid*))HookTable::Instance().HashGuid_c_str)(this);
    }

    static uint64_t StringIntern(const char *str, uint64_t size) {
        return ((uint64_t(__fastcall *)(const char *, uint64_t))HookTable::Instance().HashGuid_StringIntern)(
            str, size);
    }

  private:
    uint32_t mId;
};
} // namespace sgg