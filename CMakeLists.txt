cmake_minimum_required(VERSION 3.8)
project(mysat)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES solver.cpp)
add_executable(mysat ${SOURCE_FILES})