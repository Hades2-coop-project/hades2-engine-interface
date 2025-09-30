//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class HashGuid {
  public:
    uint32_t GetId() const noexcept { return mId; };

  private:
    uint32_t mId;
};
} // namespace sgg