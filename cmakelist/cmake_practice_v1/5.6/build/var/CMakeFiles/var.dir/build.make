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
include var/CMakeFiles/var.dir/depend.make

# Include the progress variables for this target.
include var/CMakeFiles/var.dir/progress.make

# Include the compile flags for this target's objects.
include var/CMakeFiles/var.dir/flags.make

var/CMakeFiles/var.dir/src/var.cpp.o: var/CMakeFiles/var.dir/flags.make
var/CMakeFiles/var.dir/src/var.cpp.o: ../var/src/var.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object var/CMakeFiles/var.dir/src/var.cpp.o"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/var.dir/src/var.cpp.o -c /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/var/src/var.cpp

var/CMakeFiles/var.dir/src/var.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/var.dir/src/var.cpp.i"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/var/src/var.cpp > CMakeFiles/var.dir/src/var.cpp.i

var/CMakeFiles/var.dir/src/var.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/var.dir/src/var.cpp.s"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/var/src/var.cpp -o CMakeFiles/var.dir/src/var.cpp.s

var/CMakeFiles/var.dir/src/var.cpp.o.requires:

.PHONY : var/CMakeFiles/var.dir/src/var.cpp.o.requires

var/CMakeFiles/var.dir/src/var.cpp.o.provides: var/CMakeFiles/var.dir/src/var.cpp.o.requires
	$(MAKE) -f var/CMakeFiles/var.dir/build.make var/CMakeFiles/var.dir/src/var.cpp.o.provides.build
.PHONY : var/CMakeFiles/var.dir/src/var.cpp.o.provides

var/CMakeFiles/var.dir/src/var.cpp.o.provides.build: var/CMakeFiles/var.dir/src/var.cpp.o


# Object files for target var
var_OBJECTS = \
"CMakeFiles/var.dir/src/var.cpp.o"

# External object files for target var
var_EXTERNAL_OBJECTS =

var/libvar.a: var/CMakeFiles/var.dir/src/var.cpp.o
var/libvar.a: var/CMakeFiles/var.dir/build.make
var/libvar.a: var/CMakeFiles/var.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libvar.a"
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var && $(CMAKE_COMMAND) -P CMakeFiles/var.dir/cmake_clean_target.cmake
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/var.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
var/CMakeFiles/var.dir/build: var/libvar.a

.PHONY : var/CMakeFiles/var.dir/build

var/CMakeFiles/var.dir/requires: var/CMakeFiles/var.dir/src/var.cpp.o.requires

.PHONY : var/CMakeFiles/var.dir/requires

var/CMakeFiles/var.dir/clean:
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var && $(CMAKE_COMMAND) -P CMakeFiles/var.dir/cmake_clean.cmake
.PHONY : var/CMakeFiles/var.dir/clean

var/CMakeFiles/var.dir/depend:
	cd /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5 /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/var /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var /mnt/d/suraj/etc/etc/cmakelist/cmake_practice_v1/5.5/build/var/CMakeFiles/var.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : var/CMakeFiles/var.dir/depend

