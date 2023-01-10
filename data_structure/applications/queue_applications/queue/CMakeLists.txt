cmake_minimum_required(VERSION 3.0.0)

add_library(my_queue src/queue.c)

target_link_libraries(my_queue PUBLIC my_list)

target_include_directories(my_queue PUBLIC inc)