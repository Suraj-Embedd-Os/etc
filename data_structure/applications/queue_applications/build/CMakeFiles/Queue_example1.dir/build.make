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
CMAKE_SOURCE_DIR = /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build

# Include any dependencies generated for this target.
include CMakeFiles/Queue_example1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Queue_example1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Queue_example1.dir/flags.make

CMakeFiles/Queue_example1.dir/main.c.o: CMakeFiles/Queue_example1.dir/flags.make
CMakeFiles/Queue_example1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Queue_example1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Queue_example1.dir/main.c.o   -c /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/main.c

CMakeFiles/Queue_example1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Queue_example1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/main.c > CMakeFiles/Queue_example1.dir/main.c.i

CMakeFiles/Queue_example1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Queue_example1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/main.c -o CMakeFiles/Queue_example1.dir/main.c.s

CMakeFiles/Queue_example1.dir/main.c.o.requires:

.PHONY : CMakeFiles/Queue_example1.dir/main.c.o.requires

CMakeFiles/Queue_example1.dir/main.c.o.provides: CMakeFiles/Queue_example1.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Queue_example1.dir/build.make CMakeFiles/Queue_example1.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Queue_example1.dir/main.c.o.provides

CMakeFiles/Queue_example1.dir/main.c.o.provides.build: CMakeFiles/Queue_example1.dir/main.c.o


# Object files for target Queue_example1
Queue_example1_OBJECTS = \
"CMakeFiles/Queue_example1.dir/main.c.o"

# External object files for target Queue_example1
Queue_example1_EXTERNAL_OBJECTS =

Queue_example1: CMakeFiles/Queue_example1.dir/main.c.o
Queue_example1: CMakeFiles/Queue_example1.dir/build.make
Queue_example1: list/libmy_list.a
Queue_example1: stack/libmy_stack.a
Queue_example1: queue/libmy_queue.a
Queue_example1: list/libmy_list.a
Queue_example1: CMakeFiles/Queue_example1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Queue_example1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Queue_example1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Queue_example1.dir/build: Queue_example1

.PHONY : CMakeFiles/Queue_example1.dir/build

CMakeFiles/Queue_example1.dir/requires: CMakeFiles/Queue_example1.dir/main.c.o.requires

.PHONY : CMakeFiles/Queue_example1.dir/requires

CMakeFiles/Queue_example1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Queue_example1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Queue_example1.dir/clean

CMakeFiles/Queue_example1.dir/depend:
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/CMakeFiles/Queue_example1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Queue_example1.dir/depend

