
cmake_minimum_required(VERSION 3.0.0)

add_library(var var.cpp)

target_link_libraries(var PUBLIC my_print)
