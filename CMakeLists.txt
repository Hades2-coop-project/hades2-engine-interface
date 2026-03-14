cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories (
   src/.
)

file(GLOB_RECURSE EASTL_HEADERS
	src/EASTL-forge1.51/*.h
)

file(GLOB_RECURSE HADES_MOD_CORE_FILES
	src/hades2/*.cpp
	src/hades2/*.h
)

add_library(Hades2EngineInterface STATIC
	${EASTL_HEADERS}
	${HADES_MOD_CORE_FILES}

	"src/allocator_forge_simple_impl.cpp"

	"src/HookTable.h"
	"src/HookTable.cpp"

	"src/HookedLua.h"
)
