//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

namespace sgg::fs {
class IFileSystem;

struct ResourceDirectoryInfo {
    IFileSystem *pIO;
    char path[512];
    bool bundled;
};
static_assert(sizeof(ResourceDirectoryInfo) == 0x210, "Incorrect sgg::fs::ResourceDirectoryInfo size");
} // namespace sgg