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
CMAKE_SOURCE_DIR = /mnt/d/suraj/cmakelist/my_cmake/02_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/suraj/cmakelist/my_cmake/02_cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/my_math.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_math.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_math.dir/flags.make

CMakeFiles/my_math.dir/addition.cpp.o: CMakeFiles/my_math.dir/flags.make
CMakeFiles/my_math.dir/addition.cpp.o: ../addition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/cmakelist/my_cmake/02_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_math.dir/addition.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_math.dir/addition.cpp.o -c /mnt/d/suraj/cmakelist/my_cmake/02_cmake/addition.cpp

CMakeFiles/my_math.dir/addition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_math.dir/addition.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/suraj/cmakelist/my_cmake/02_cmake/addition.cpp > CMakeFiles/my_math.dir/addition.cpp.i

CMakeFiles/my_math.dir/addition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_math.dir/addition.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/suraj/cmakelist/my_cmake/02_cmake/addition.cpp -o CMakeFiles/my_math.dir/addition.cpp.s

CMakeFiles/my_math.dir/addition.cpp.o.requires:

.PHONY : CMakeFiles/my_math.dir/addition.cpp.o.requires

CMakeFiles/my_math.dir/addition.cpp.o.provides: CMakeFiles/my_math.dir/addition.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_math.dir/build.make CMakeFiles/my_math.dir/addition.cpp.o.provides.build
.PHONY : CMakeFiles/my_math.dir/addition.cpp.o.provides

CMakeFiles/my_math.dir/addition.cpp.o.provides.build: CMakeFiles/my_math.dir/addition.cpp.o


CMakeFiles/my_math.dir/division.cpp.o: CMakeFiles/my_math.dir/flags.make
CMakeFiles/my_math.dir/division.cpp.o: ../division.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/cmakelist/my_cmake/02_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_math.dir/division.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_math.dir/division.cpp.o -c /mnt/d/suraj/cmakelist/my_cmake/02_cmake/division.cpp

CMakeFiles/my_math.dir/division.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_math.dir/division.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/suraj/cmakelist/my_cmake/02_cmake/division.cpp > CMakeFiles/my_math.dir/division.cpp.i

CMakeFiles/my_math.dir/division.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_math.dir/division.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/suraj/cmakelist/my_cmake/02_cmake/division.cpp -o CMakeFiles/my_math.dir/division.cpp.s

CMakeFiles/my_math.dir/division.cpp.o.requires:

.PHONY : CMakeFiles/my_math.dir/division.cpp.o.requires

CMakeFiles/my_math.dir/division.cpp.o.provides: CMakeFiles/my_math.dir/division.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_math.dir/build.make CMakeFiles/my_math.dir/division.cpp.o.provides.build
.PHONY : CMakeFiles/my_math.dir/division.cpp.o.provides

CMakeFiles/my_math.dir/division.cpp.o.provides.build: CMakeFiles/my_math.dir/division.cpp.o


# Object files for target my_math
my_math_OBJECTS = \
"CMakeFiles/my_math.dir/addition.cpp.o" \
"CMakeFiles/my_math.dir/division.cpp.o"

# External object files for target my_math
my_math_EXTERNAL_OBJECTS =

libmy_math.a: CMakeFiles/my_math.dir/addition.cpp.o
libmy_math.a: CMakeFiles/my_math.dir/division.cpp.o
libmy_math.a: CMakeFiles/my_math.dir/build.make
libmy_math.a: CMakeFiles/my_math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/cmakelist/my_cmake/02_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmy_math.a"
	$(CMAKE_COMMAND) -P CMakeFiles/my_math.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_math.dir/build: libmy_math.a

.PHONY : CMakeFiles/my_math.dir/build

CMakeFiles/my_math.dir/requires: CMakeFiles/my_math.dir/addition.cpp.o.requires
CMakeFiles/my_math.dir/requires: CMakeFiles/my_math.dir/division.cpp.o.requires

.PHONY : CMakeFiles/my_math.dir/requires

CMakeFiles/my_math.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_math.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_math.dir/clean

CMakeFiles/my_math.dir/depend:
	cd /mnt/d/suraj/cmakelist/my_cmake/02_cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/cmakelist/my_cmake/02_cmake /mnt/d/suraj/cmakelist/my_cmake/02_cmake /mnt/d/suraj/cmakelist/my_cmake/02_cmake/build /mnt/d/suraj/cmakelist/my_cmake/02_cmake/build /mnt/d/suraj/cmakelist/my_cmake/02_cmake/build/CMakeFiles/my_math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_math.dir/depend

