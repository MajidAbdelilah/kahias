# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ain/projects/khias/lib/cJSON-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ain/projects/khias/lib/cJSON-master

# Include any dependencies generated for this target.
include tests/CMakeFiles/cjson_add.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/cjson_add.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/cjson_add.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/cjson_add.dir/flags.make

tests/CMakeFiles/cjson_add.dir/cjson_add.c.o: tests/CMakeFiles/cjson_add.dir/flags.make
tests/CMakeFiles/cjson_add.dir/cjson_add.c.o: tests/cjson_add.c
tests/CMakeFiles/cjson_add.dir/cjson_add.c.o: tests/CMakeFiles/cjson_add.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ain/projects/khias/lib/cJSON-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/cjson_add.dir/cjson_add.c.o"
	cd /home/ain/projects/khias/lib/cJSON-master/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/cjson_add.dir/cjson_add.c.o -MF CMakeFiles/cjson_add.dir/cjson_add.c.o.d -o CMakeFiles/cjson_add.dir/cjson_add.c.o -c /home/ain/projects/khias/lib/cJSON-master/tests/cjson_add.c

tests/CMakeFiles/cjson_add.dir/cjson_add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cjson_add.dir/cjson_add.c.i"
	cd /home/ain/projects/khias/lib/cJSON-master/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ain/projects/khias/lib/cJSON-master/tests/cjson_add.c > CMakeFiles/cjson_add.dir/cjson_add.c.i

tests/CMakeFiles/cjson_add.dir/cjson_add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cjson_add.dir/cjson_add.c.s"
	cd /home/ain/projects/khias/lib/cJSON-master/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ain/projects/khias/lib/cJSON-master/tests/cjson_add.c -o CMakeFiles/cjson_add.dir/cjson_add.c.s

# Object files for target cjson_add
cjson_add_OBJECTS = \
"CMakeFiles/cjson_add.dir/cjson_add.c.o"

# External object files for target cjson_add
cjson_add_EXTERNAL_OBJECTS =

tests/cjson_add: tests/CMakeFiles/cjson_add.dir/cjson_add.c.o
tests/cjson_add: tests/CMakeFiles/cjson_add.dir/build.make
tests/cjson_add: libcjson.so.1.7.15
tests/cjson_add: tests/libunity.a
tests/cjson_add: tests/CMakeFiles/cjson_add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ain/projects/khias/lib/cJSON-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cjson_add"
	cd /home/ain/projects/khias/lib/cJSON-master/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cjson_add.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/cjson_add.dir/build: tests/cjson_add
.PHONY : tests/CMakeFiles/cjson_add.dir/build

tests/CMakeFiles/cjson_add.dir/clean:
	cd /home/ain/projects/khias/lib/cJSON-master/tests && $(CMAKE_COMMAND) -P CMakeFiles/cjson_add.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/cjson_add.dir/clean

tests/CMakeFiles/cjson_add.dir/depend:
	cd /home/ain/projects/khias/lib/cJSON-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ain/projects/khias/lib/cJSON-master /home/ain/projects/khias/lib/cJSON-master/tests /home/ain/projects/khias/lib/cJSON-master /home/ain/projects/khias/lib/cJSON-master/tests /home/ain/projects/khias/lib/cJSON-master/tests/CMakeFiles/cjson_add.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/cjson_add.dir/depend
