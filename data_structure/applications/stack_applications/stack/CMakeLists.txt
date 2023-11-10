
cmake_minimum_required(VERSION 3.0.0)

add_library(my_stack src/stack.c)

target_link_libraries(my_stack PUBLIC my_list)

target_include_directories(my_stack PUBLIC inc)