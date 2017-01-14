cmake_minimum_required(VERSION 3.6)
project(MicroMouse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src)
include_directories(src/main)
include_directories(src/main/cc)
include_directories(src/main/c)
include_directories(src/test/c)
include_directories(src/test/cc)

FILE(GLOB_RECURSE SRCFILES src/main/cc/*.cc src/main/cc/*.h src/test/cc/*.cc)

set(SOURCE_FILES ${SRCFILES} main.cc src/test/cc/util/UtilTests.cc src/test/cc/maze/cell/CellTests.cc)

add_executable(MicroMouse ${SOURCE_FILES})