//
// Copyright (c) Uladzislau Nikalayevich <thenormalnij@gmail.com>. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.
//

#pragma once

#include "HookTable.h"
#include "ResourceDirectoryInfo.h"

namespace sgg::fs {
class IFileSystem;

enum class ResourceDirectory : int32_t {
    RD_SHADER_BINARIES = 0x0,
    RD_SHADER_SOURCES = 0x1,
    RD_PIPELINE_CACHE = 0x2,
    RD_TEXTURES = 0x3,
    RD_MESHES = 0x4,
    RD_FONTS = 0x5,
    RD_ANIMATIONS = 0x6,
    RD_AUDIO = 0x7,
    RD_GPU_CONFIG = 0x8,
    RD_LOG = 0x9,
    RD_SCRIPTS = 0xA,
    RD_OTHER_FILES = 0xB,
    ____rd_lib_counter_begin = 0xC,
    RD_MIDDLEWARE_0 = 0xC,
    RD_MIDDLEWARE_1 = 0xD,
    RD_MIDDLEWARE_2 = 0xE,
    RD_MIDDLEWARE_3 = 0xF,
    RD_MIDDLEWARE_4 = 0x10,
    RD_MIDDLEWARE_5 = 0x11,
    RD_MIDDLEWARE_6 = 0x12,
    RD_MIDDLEWARE_7 = 0x13,
    RD_MIDDLEWARE_8 = 0x14,
    RD_MIDDLEWARE_9 = 0x15,
    RD_MIDDLEWARE_10 = 0x16,
    RD_MIDDLEWARE_11 = 0x17,
    RD_MIDDLEWARE_12 = 0x18,
    RD_MIDDLEWARE_13 = 0x19,
    RD_MIDDLEWARE_14 = 0x1A,
    RD_MIDDLEWARE_15 = 0x1B,
    ____rd_lib_counter_end = 0xD2,
    RD_COUNT = 0xD3,
    // The game has no defenitions for these resources
    CALCULATES_TEXT = 0x1C,
};

enum class ResourceMount : int32_t {
    RM_CONTENT = 0x0,
    RM_DEBUG = 0x1,
    RM_SAVE_0 = 0x2,
    RM_COUNT = 0x3,
};

static void fsSetPathForResourceDir(IFileSystem *pIO, ResourceMount mount, ResourceDirectory id, const char *path) {
    reinterpret_cast<void(__fastcall *)(void *pIO, ResourceMount mount, ResourceDirectory id, const char *path)>(
        HookTable::Instance().fsSetPathForResourceDir)(pIO, mount, id, path);
}

using gResourceDirectories_t = ResourceDirectoryInfo[211];

static gResourceDirectories_t *GetResourcesDir() {
    return reinterpret_cast<gResourceDirectories_t *>(HookTable::Instance().gResourceDirectories);
}

static ResourceDirectoryInfo *GetResourceDir(ResourceDirectory id) {
    return reinterpret_cast<ResourceDirectoryInfo *>(HookTable::Instance().gResourceDirectories + static_cast<size_t>(id) * sizeof(ResourceDirectoryInfo));
}
} // namespace sgg::fs
