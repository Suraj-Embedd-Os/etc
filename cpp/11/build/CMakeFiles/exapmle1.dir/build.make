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
CMAKE_SOURCE_DIR = /mnt/d/suraj/etc/etc/cpp/11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/suraj/etc/etc/cpp/11/build

# Include any dependencies generated for this target.
include CMakeFiles/exapmle1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exapmle1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exapmle1.dir/flags.make

CMakeFiles/exapmle1.dir/main.cpp.o: CMakeFiles/exapmle1.dir/flags.make
CMakeFiles/exapmle1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/cpp/11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exapmle1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exapmle1.dir/main.cpp.o -c /mnt/d/suraj/etc/etc/cpp/11/main.cpp

CMakeFiles/exapmle1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exapmle1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/suraj/etc/etc/cpp/11/main.cpp > CMakeFiles/exapmle1.dir/main.cpp.i

CMakeFiles/exapmle1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exapmle1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/suraj/etc/etc/cpp/11/main.cpp -o CMakeFiles/exapmle1.dir/main.cpp.s

CMakeFiles/exapmle1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/exapmle1.dir/main.cpp.o.requires

CMakeFiles/exapmle1.dir/main.cpp.o.provides: CMakeFiles/exapmle1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/exapmle1.dir/build.make CMakeFiles/exapmle1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/exapmle1.dir/main.cpp.o.provides

CMakeFiles/exapmle1.dir/main.cpp.o.provides.build: CMakeFiles/exapmle1.dir/main.cpp.o


# Object files for target exapmle1
exapmle1_OBJECTS = \
"CMakeFiles/exapmle1.dir/main.cpp.o"

# External object files for target exapmle1
exapmle1_EXTERNAL_OBJECTS =

exapmle1: CMakeFiles/exapmle1.dir/main.cpp.o
exapmle1: CMakeFiles/exapmle1.dir/build.make
exapmle1: CMakeFiles/exapmle1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/etc/etc/cpp/11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exapmle1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exapmle1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exapmle1.dir/build: exapmle1

.PHONY : CMakeFiles/exapmle1.dir/build

CMakeFiles/exapmle1.dir/requires: CMakeFiles/exapmle1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/exapmle1.dir/requires

CMakeFiles/exapmle1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exapmle1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exapmle1.dir/clean

CMakeFiles/exapmle1.dir/depend:
	cd /mnt/d/suraj/etc/etc/cpp/11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/etc/etc/cpp/11 /mnt/d/suraj/etc/etc/cpp/11 /mnt/d/suraj/etc/etc/cpp/11/build /mnt/d/suraj/etc/etc/cpp/11/build /mnt/d/suraj/etc/etc/cpp/11/build/CMakeFiles/exapmle1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exapmle1.dir/depend
