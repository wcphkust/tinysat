cmake_minimum_required(VERSION 3.8)
project(tinysat)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/solver.cpp src/Logic/CNF.cpp src/Logic/LiteralTerm.cpp src/Logic/LiteralTerm.h src/Logic/Utils.cpp src/Logic/Utils.h src/Logic/DisClause.cpp src/Logic/DisClause.h)
add_executable(tinysat ${SOURCE_FILES})