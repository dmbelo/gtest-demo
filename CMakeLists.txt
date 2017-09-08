cmake_minimum_required (VERSION 3.5)

project(gtest-demo)

add_definitions(-std=c++11)

enable_language(C)
enable_language(CXX)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(sources demo.cpp)

add_executable(gtest-demo ${sources})

target_link_libraries(gtest-demo gtest gtest_main pthread)