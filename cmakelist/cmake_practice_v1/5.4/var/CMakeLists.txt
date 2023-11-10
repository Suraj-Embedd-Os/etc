cmake_minimum_required(VERSION 3.0.0)

add_library(var src/var.cpp)

target_link_libraries(var PUBLIC my_print)

target_include_directories(var PUBLIC inc)
