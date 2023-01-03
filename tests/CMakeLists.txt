cmake_minimum_required(VERSION 3.16)
project(test-utf8)

add_executable(test-utf8 main_test.cpp catch_amalgamated.cpp)
target_compile_features(test-utf8 PRIVATE cxx_std_17)

target_link_libraries(test-utf8 utf-8-parser)

add_test(NAME GeneralParserTest COMMAND test-utf8)