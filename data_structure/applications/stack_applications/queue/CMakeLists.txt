cmake_minimum_required(VERSION 3.0.0)

add_library(my_queue src/queue.c)

target_include_directories(my_queue PUBLIC inc)