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
CMAKE_SOURCE_DIR = /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build

# Include any dependencies generated for this target.
include stack/CMakeFiles/my_stack.dir/depend.make

# Include the progress variables for this target.
include stack/CMakeFiles/my_stack.dir/progress.make

# Include the compile flags for this target's objects.
include stack/CMakeFiles/my_stack.dir/flags.make

stack/CMakeFiles/my_stack.dir/src/stack.c.o: stack/CMakeFiles/my_stack.dir/flags.make
stack/CMakeFiles/my_stack.dir/src/stack.c.o: ../stack/src/stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object stack/CMakeFiles/my_stack.dir/src/stack.c.o"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_stack.dir/src/stack.c.o   -c /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/stack/src/stack.c

stack/CMakeFiles/my_stack.dir/src/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_stack.dir/src/stack.c.i"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/stack/src/stack.c > CMakeFiles/my_stack.dir/src/stack.c.i

stack/CMakeFiles/my_stack.dir/src/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_stack.dir/src/stack.c.s"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/stack/src/stack.c -o CMakeFiles/my_stack.dir/src/stack.c.s

stack/CMakeFiles/my_stack.dir/src/stack.c.o.requires:

.PHONY : stack/CMakeFiles/my_stack.dir/src/stack.c.o.requires

stack/CMakeFiles/my_stack.dir/src/stack.c.o.provides: stack/CMakeFiles/my_stack.dir/src/stack.c.o.requires
	$(MAKE) -f stack/CMakeFiles/my_stack.dir/build.make stack/CMakeFiles/my_stack.dir/src/stack.c.o.provides.build
.PHONY : stack/CMakeFiles/my_stack.dir/src/stack.c.o.provides

stack/CMakeFiles/my_stack.dir/src/stack.c.o.provides.build: stack/CMakeFiles/my_stack.dir/src/stack.c.o


# Object files for target my_stack
my_stack_OBJECTS = \
"CMakeFiles/my_stack.dir/src/stack.c.o"

# External object files for target my_stack
my_stack_EXTERNAL_OBJECTS =

stack/libmy_stack.a: stack/CMakeFiles/my_stack.dir/src/stack.c.o
stack/libmy_stack.a: stack/CMakeFiles/my_stack.dir/build.make
stack/libmy_stack.a: stack/CMakeFiles/my_stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libmy_stack.a"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack && $(CMAKE_COMMAND) -P CMakeFiles/my_stack.dir/cmake_clean_target.cmake
	cd /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_stack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
stack/CMakeFiles/my_stack.dir/build: stack/libmy_stack.a

.PHONY : stack/CMakeFiles/my_stack.dir/build

stack/CMakeFiles/my_stack.dir/requires: stack/CMakeFiles/my_stack.dir/src/stack.c.o.requires

.PHONY : stack/CMakeFiles/my_stack.dir/requires

stack/CMakeFiles/my_stack.dir/clean:
	cd /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack && $(CMAKE_COMMAND) -P CMakeFiles/my_stack.dir/cmake_clean.cmake
.PHONY : stack/CMakeFiles/my_stack.dir/clean

stack/CMakeFiles/my_stack.dir/depend:
	cd /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/stack /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack /mnt/d/suraj/etc/etc/data_structure/applications/stack_applications/build/stack/CMakeFiles/my_stack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : stack/CMakeFiles/my_stack.dir/depend

