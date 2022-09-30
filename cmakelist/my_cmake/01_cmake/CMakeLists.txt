cmake_minimum_required(VERSION 3.0.0)

project(Calculator VERSION 3.0.0)

add_executable(cal main.cpp
					addition.cpp division.cpp
					print_result.cpp)