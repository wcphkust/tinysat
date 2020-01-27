cmake_minimum_required(VERSION 3.8)
project(tinysat)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES solver.cpp CNF.cpp)
add_executable(tinysat ${SOURCE_FILES})