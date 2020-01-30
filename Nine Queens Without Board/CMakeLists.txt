cmake_minimum_required(VERSION 3.14)
project(NineQueens)

set(CMAKE_CXX_STANDARD 11)

add_executable(SandBox "Nine Queens Without Board.cpp" "Nine Queens Without Board Test.cpp" Utils.cpp Utils.h)
