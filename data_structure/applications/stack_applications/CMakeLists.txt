cmake_minimum_required(VERSION 3.0.0)

project(Stack_Applications)

add_subdirectory(list)
add_subdirectory(queue)
add_subdirectory(stack)


add_executable(stack_example1 main.c)

target_link_libraries(stack_example1 PUBLIC my_list my_stack my_queue)
#target_include_directories(stack_example1 PUBLIC list stack queue)


