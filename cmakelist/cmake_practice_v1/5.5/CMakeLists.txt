cmake_minimum_required(VERSION 3.0.0)

project(calculatorProject)

add_subdirectory(math)
add_subdirectory(print)
add_subdirectory(var)


add_executable(calculator main.cpp ./var/libtest.o)


#add_library(my_test test.cpp)
target_link_libraries(calculator PUBLIC var my_math my_print)
include_directories(./var)