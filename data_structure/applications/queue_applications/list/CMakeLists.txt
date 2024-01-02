cmake_minimum_required(VERSION 3.0.0)

add_library(my_list src/linkList.c)

target_include_directories(my_list PUBLIC inc)