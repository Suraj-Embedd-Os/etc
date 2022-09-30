cmake_minimum_required(VERSION 2.8.10)

project(Example_for_Cmake)

set(VERSION 2.8.10)
set(DISCRIPTION "Example for Cmake Project")
SET(CMAKE_POSITIONAL_INDEPENDENT ON)

add_subdirectory(external)
include(external/boost/CMakeLists.txt)
add_subdirectory(app)
add_subdirectory(library)