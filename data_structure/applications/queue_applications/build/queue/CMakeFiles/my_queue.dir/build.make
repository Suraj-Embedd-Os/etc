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
include queue/CMakeFiles/my_queue.dir/depend.make

# Include the progress variables for this target.
include queue/CMakeFiles/my_queue.dir/progress.make

# Include the compile flags for this target's objects.
include queue/CMakeFiles/my_queue.dir/flags.make

queue/CMakeFiles/my_queue.dir/src/queue.c.o: queue/CMakeFiles/my_queue.dir/flags.make
queue/CMakeFiles/my_queue.dir/src/queue.c.o: ../queue/src/queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object queue/CMakeFiles/my_queue.dir/src/queue.c.o"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_queue.dir/src/queue.c.o   -c /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/queue/src/queue.c

queue/CMakeFiles/my_queue.dir/src/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_queue.dir/src/queue.c.i"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/queue/src/queue.c > CMakeFiles/my_queue.dir/src/queue.c.i

queue/CMakeFiles/my_queue.dir/src/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_queue.dir/src/queue.c.s"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/queue/src/queue.c -o CMakeFiles/my_queue.dir/src/queue.c.s

queue/CMakeFiles/my_queue.dir/src/queue.c.o.requires:

.PHONY : queue/CMakeFiles/my_queue.dir/src/queue.c.o.requires

queue/CMakeFiles/my_queue.dir/src/queue.c.o.provides: queue/CMakeFiles/my_queue.dir/src/queue.c.o.requires
	$(MAKE) -f queue/CMakeFiles/my_queue.dir/build.make queue/CMakeFiles/my_queue.dir/src/queue.c.o.provides.build
.PHONY : queue/CMakeFiles/my_queue.dir/src/queue.c.o.provides

queue/CMakeFiles/my_queue.dir/src/queue.c.o.provides.build: queue/CMakeFiles/my_queue.dir/src/queue.c.o


# Object files for target my_queue
my_queue_OBJECTS = \
"CMakeFiles/my_queue.dir/src/queue.c.o"

# External object files for target my_queue
my_queue_EXTERNAL_OBJECTS =

queue/libmy_queue.a: queue/CMakeFiles/my_queue.dir/src/queue.c.o
queue/libmy_queue.a: queue/CMakeFiles/my_queue.dir/build.make
queue/libmy_queue.a: queue/CMakeFiles/my_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libmy_queue.a"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue && $(CMAKE_COMMAND) -P CMakeFiles/my_queue.dir/cmake_clean_target.cmake
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
queue/CMakeFiles/my_queue.dir/build: queue/libmy_queue.a

.PHONY : queue/CMakeFiles/my_queue.dir/build

queue/CMakeFiles/my_queue.dir/requires: queue/CMakeFiles/my_queue.dir/src/queue.c.o.requires

.PHONY : queue/CMakeFiles/my_queue.dir/requires

queue/CMakeFiles/my_queue.dir/clean:
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue && $(CMAKE_COMMAND) -P CMakeFiles/my_queue.dir/cmake_clean.cmake
.PHONY : queue/CMakeFiles/my_queue.dir/clean

queue/CMakeFiles/my_queue.dir/depend:
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/queue /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/queue/CMakeFiles/my_queue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : queue/CMakeFiles/my_queue.dir/depend

