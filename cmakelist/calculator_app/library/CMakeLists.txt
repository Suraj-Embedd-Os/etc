cmake_minimum_required(VERSION 2.8.10)

project(MathLibs)
set(VERSION 1.0.0)
set(DESCRIPTION "The Internal Math-libraries")

set(BASIC_SOURCE "src/BasicMath.cpp"
				 "src/HeavyMath.cpp"
				 "${CMAKE_CURRENT_SOURCE_DIR}/include/Math.h"
				 "${CMAKE_CURRENT_SOURCE_DIR}/include/MathApi.h"
				 )
				 
add_library(basicmath_objLib OBJECT $BASIC_SOURCE)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" CACHE STRING "C++ compiler-flag" FORCE)

include_directories(SYSTEM "{<TARGET_PROPERTY:Boost::outcome,MY_INCLUDE_DIRS>")

get_target_property(props Boost::outcome MY_COMPILE_FEATURES )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${props}" CACHE STRING C++ compiler-flag" FORCE)

add_library(basicmath_objLib SHARED $<TARGET_OBJECTS:basicmath_objLib>)

add_library(extmath SHARED "src/ExtendedMath.cpp" $<TARGET_OBJECTS:basicmath_objLib>)

include_directories(SYSTEM "${Boost_INCLDUE_DIRS}")

target_link_libraries(extmath ${Boost_LIBRARIES})

