cmake_minimum_required(VERSION 3.15)
project(words)

set(CMAKE_CXX_STANDARD 11)

add_executable(words words.cpp words_test.cpp Word.cpp Word.h)
