cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories (
   src/.
)

file(GLOB_RECURSE HADES_MOD_CORE_FILES src/*.cpp src/*.h)

add_library(Hades2EngineInterface STATIC ${HADES_MOD_CORE_FILES})
