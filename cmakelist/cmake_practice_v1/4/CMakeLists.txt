cmake_minimum_required(VERSION 3.0.0)

project(calculatorProject)

add_subdirectory(math)
add_subdirectory(print)


add_executable(calculator main.cpp )

target_link_libraries(calculator PUBLIC my_math my_print)
target_include_directories(calculator PUBLIC math print)


