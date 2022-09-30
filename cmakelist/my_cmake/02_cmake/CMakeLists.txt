cmake_minimum_required(VERSION 3.0.0)

project(Calculator VERSION 3.0.0)

add_library(my_print print_result.cpp)
add_library(my_math addition.cpp division.cpp)


add_executable(cal main.cpp)

target_link_libraries(cal PUBLIC  my_print my_math )