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
include list/CMakeFiles/my_list.dir/depend.make

# Include the progress variables for this target.
include list/CMakeFiles/my_list.dir/progress.make

# Include the compile flags for this target's objects.
include list/CMakeFiles/my_list.dir/flags.make

list/CMakeFiles/my_list.dir/src/linkList.c.o: list/CMakeFiles/my_list.dir/flags.make
list/CMakeFiles/my_list.dir/src/linkList.c.o: ../list/src/linkList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object list/CMakeFiles/my_list.dir/src/linkList.c.o"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_list.dir/src/linkList.c.o   -c /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/list/src/linkList.c

list/CMakeFiles/my_list.dir/src/linkList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_list.dir/src/linkList.c.i"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/list/src/linkList.c > CMakeFiles/my_list.dir/src/linkList.c.i

list/CMakeFiles/my_list.dir/src/linkList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_list.dir/src/linkList.c.s"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/list/src/linkList.c -o CMakeFiles/my_list.dir/src/linkList.c.s

list/CMakeFiles/my_list.dir/src/linkList.c.o.requires:

.PHONY : list/CMakeFiles/my_list.dir/src/linkList.c.o.requires

list/CMakeFiles/my_list.dir/src/linkList.c.o.provides: list/CMakeFiles/my_list.dir/src/linkList.c.o.requires
	$(MAKE) -f list/CMakeFiles/my_list.dir/build.make list/CMakeFiles/my_list.dir/src/linkList.c.o.provides.build
.PHONY : list/CMakeFiles/my_list.dir/src/linkList.c.o.provides

list/CMakeFiles/my_list.dir/src/linkList.c.o.provides.build: list/CMakeFiles/my_list.dir/src/linkList.c.o


# Object files for target my_list
my_list_OBJECTS = \
"CMakeFiles/my_list.dir/src/linkList.c.o"

# External object files for target my_list
my_list_EXTERNAL_OBJECTS =

list/libmy_list.a: list/CMakeFiles/my_list.dir/src/linkList.c.o
list/libmy_list.a: list/CMakeFiles/my_list.dir/build.make
list/libmy_list.a: list/CMakeFiles/my_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libmy_list.a"
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list && $(CMAKE_COMMAND) -P CMakeFiles/my_list.dir/cmake_clean_target.cmake
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
list/CMakeFiles/my_list.dir/build: list/libmy_list.a

.PHONY : list/CMakeFiles/my_list.dir/build

list/CMakeFiles/my_list.dir/requires: list/CMakeFiles/my_list.dir/src/linkList.c.o.requires

.PHONY : list/CMakeFiles/my_list.dir/requires

list/CMakeFiles/my_list.dir/clean:
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list && $(CMAKE_COMMAND) -P CMakeFiles/my_list.dir/cmake_clean.cmake
.PHONY : list/CMakeFiles/my_list.dir/clean

list/CMakeFiles/my_list.dir/depend:
	cd /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/list /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list /mnt/d/suraj/etc/etc/data_structure/applications/queue_applications/build/list/CMakeFiles/my_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : list/CMakeFiles/my_list.dir/depend

