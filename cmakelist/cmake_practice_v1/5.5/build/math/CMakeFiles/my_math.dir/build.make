# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build

# Include any dependencies generated for this target.
include math/CMakeFiles/my_math.dir/depend.make

# Include the progress variables for this target.
include math/CMakeFiles/my_math.dir/progress.make

# Include the compile flags for this target's objects.
include math/CMakeFiles/my_math.dir/flags.make

math/CMakeFiles/my_math.dir/src/addition.cpp.o: math/CMakeFiles/my_math.dir/flags.make
math/CMakeFiles/my_math.dir/src/addition.cpp.o: ../math/src/addition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object math/CMakeFiles/my_math.dir/src/addition.cpp.o"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_math.dir/src/addition.cpp.o -c /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/math/src/addition.cpp

math/CMakeFiles/my_math.dir/src/addition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_math.dir/src/addition.cpp.i"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/math/src/addition.cpp > CMakeFiles/my_math.dir/src/addition.cpp.i

math/CMakeFiles/my_math.dir/src/addition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_math.dir/src/addition.cpp.s"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/math/src/addition.cpp -o CMakeFiles/my_math.dir/src/addition.cpp.s

math/CMakeFiles/my_math.dir/src/addition.cpp.o.requires:

.PHONY : math/CMakeFiles/my_math.dir/src/addition.cpp.o.requires

math/CMakeFiles/my_math.dir/src/addition.cpp.o.provides: math/CMakeFiles/my_math.dir/src/addition.cpp.o.requires
	$(MAKE) -f math/CMakeFiles/my_math.dir/build.make math/CMakeFiles/my_math.dir/src/addition.cpp.o.provides.build
.PHONY : math/CMakeFiles/my_math.dir/src/addition.cpp.o.provides

math/CMakeFiles/my_math.dir/src/addition.cpp.o.provides.build: math/CMakeFiles/my_math.dir/src/addition.cpp.o


math/CMakeFiles/my_math.dir/src/division.cpp.o: math/CMakeFiles/my_math.dir/flags.make
math/CMakeFiles/my_math.dir/src/division.cpp.o: ../math/src/division.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object math/CMakeFiles/my_math.dir/src/division.cpp.o"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_math.dir/src/division.cpp.o -c /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/math/src/division.cpp

math/CMakeFiles/my_math.dir/src/division.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_math.dir/src/division.cpp.i"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/math/src/division.cpp > CMakeFiles/my_math.dir/src/division.cpp.i

math/CMakeFiles/my_math.dir/src/division.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_math.dir/src/division.cpp.s"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/math/src/division.cpp -o CMakeFiles/my_math.dir/src/division.cpp.s

math/CMakeFiles/my_math.dir/src/division.cpp.o.requires:

.PHONY : math/CMakeFiles/my_math.dir/src/division.cpp.o.requires

math/CMakeFiles/my_math.dir/src/division.cpp.o.provides: math/CMakeFiles/my_math.dir/src/division.cpp.o.requires
	$(MAKE) -f math/CMakeFiles/my_math.dir/build.make math/CMakeFiles/my_math.dir/src/division.cpp.o.provides.build
.PHONY : math/CMakeFiles/my_math.dir/src/division.cpp.o.provides

math/CMakeFiles/my_math.dir/src/division.cpp.o.provides.build: math/CMakeFiles/my_math.dir/src/division.cpp.o


# Object files for target my_math
my_math_OBJECTS = \
"CMakeFiles/my_math.dir/src/addition.cpp.o" \
"CMakeFiles/my_math.dir/src/division.cpp.o"

# External object files for target my_math
my_math_EXTERNAL_OBJECTS =

math/libmy_math.a: math/CMakeFiles/my_math.dir/src/addition.cpp.o
math/libmy_math.a: math/CMakeFiles/my_math.dir/src/division.cpp.o
math/libmy_math.a: math/CMakeFiles/my_math.dir/build.make
math/libmy_math.a: math/CMakeFiles/my_math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmy_math.a"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && $(CMAKE_COMMAND) -P CMakeFiles/my_math.dir/cmake_clean_target.cmake
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/CMakeFiles/my_math.dir/build: math/libmy_math.a

.PHONY : math/CMakeFiles/my_math.dir/build

math/CMakeFiles/my_math.dir/requires: math/CMakeFiles/my_math.dir/src/addition.cpp.o.requires
math/CMakeFiles/my_math.dir/requires: math/CMakeFiles/my_math.dir/src/division.cpp.o.requires

.PHONY : math/CMakeFiles/my_math.dir/requires

math/CMakeFiles/my_math.dir/clean:
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math && $(CMAKE_COMMAND) -P CMakeFiles/my_math.dir/cmake_clean.cmake
.PHONY : math/CMakeFiles/my_math.dir/clean

math/CMakeFiles/my_math.dir/depend:
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5 /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/math /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/math/CMakeFiles/my_math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : math/CMakeFiles/my_math.dir/depend
