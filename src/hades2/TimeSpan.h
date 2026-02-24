//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg {
class TimeSpan {
  public:

  private:
    uint64_t mId;
};
static_assert(sizeof(TimeSpan) == 0x8, "Incorrect sgg::TimeSpan size");
} // namespace sgg