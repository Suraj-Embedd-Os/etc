cmake_minimum_required(VERSION 3.0.0)


add_library(my_print src/print_result.cpp)

target_include_directories(my_print PUBLIC inc)