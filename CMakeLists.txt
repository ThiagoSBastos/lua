cmake_minimum_required(VERSION 3.22)
project(luacpp LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS ON)

option(LUA_ENABLE_TESTING "Build and run tests" OFF)

enable_testing()

if(${PROJECT_NAME} STREQUAL ${CMAKE_PROJECT_NAME})
    set(TOP_LEVEL TRUE)
else()
    set(TOP_LEVEL FALSE)
endif()

if(LUA_ENABLE_TESTING)
    add_test(NAME ltestsuite COMMAND lua -e "_U=true" all.lua WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()

# Build details

add_compile_options(
    -Wall
    -O2
    -Wfatal-errors
    -Wextra
    -pedantic
    -Wshadow
    -Wundef
    -Wwrite-strings
    -Wredundant-decls
    -Wdisabled-optimization
    -Wdouble-promotion
    -Wmissing-declarations
    -Wlogical-op
    -Wno-aggressive-loop-optimizations
    -fuse-ld=gold
    -fno-stack-protector
    -fno-common
    -march=native
)

add_definitions(
    -DLUA_USE_LINUX
    -DLUA_USE_READLINE
)

set(SOURCES
    src/lapi.cpp
    src/lauxlib.cpp
    src/lbaselib.cpp
    src/lcode.cpp
    src/lcorolib.cpp
    src/lctype.cpp
    src/ldblib.cpp
    src/ldebug.cpp
    src/ldo.cpp
    src/ldump.cpp
    src/lfunc.cpp
    src/lgc.cpp
    src/linit.cpp
    src/liolib.cpp
    src/llex.cpp
    src/lmem.cpp
    src/loadlib.cpp
    src/lobject.cpp
    src/lopcodes.cpp
    src/lparser.cpp
    src/loslib.cpp
    src/lstate.cpp
    src/lstring.cpp
    src/lstrlib.cpp
    src/ltable.cpp
    src/ltablib.cpp
    src/ltm.cpp
    src/lundump.cpp
    src/lutf8lib.cpp
    src/lvm.cpp
    src/lzio.cpp
    src/lmathlib.cpp
)

add_library(Lua STATIC ${SOURCES})
set_property(TARGET Lua PROPERTY POSITION_INDEPENDENT_CODE ON)

add_executable(lua src/lua.cpp)
target_link_libraries(lua Lua m readline dl)
target_compile_definitions(lua PUBLIC LUAI_ASSERT)
