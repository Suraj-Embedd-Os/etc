option(USE_MYMATH "Use tutorial provided math implementation" ON)
cmake_minimum_required(VERSION 3.10)

# set projetc name
project(Tutorial VERSION 1.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(TutorialConfig.h.in TutorialConfig.h)

if(USE_MYMATH)
	#add MathFunctions 
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)
	list(APPEND EXTRA_INCLUDE "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

#add  the execulatble
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}"
							"${EXTRA_INCLUDE}"
							)

