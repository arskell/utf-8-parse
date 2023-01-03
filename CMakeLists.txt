cmake_minimum_required(VERSION 3.16)
project(utf-8-parser)
include_directories(include)

enable_testing()
add_subdirectory(tests)

add_library(utf-8-parser src/utf-8.cpp)