# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = E:\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CLionProject\algorithm-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLionProject\algorithm-c\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algorithm_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithm_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithm_c.dir/flags.make

CMakeFiles/algorithm_c.dir/main.c.obj: CMakeFiles/algorithm_c.dir/flags.make
CMakeFiles/algorithm_c.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLionProject\algorithm-c\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/algorithm_c.dir/main.c.obj"
	E:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\algorithm_c.dir\main.c.obj   -c E:\CLionProject\algorithm-c\main.c

CMakeFiles/algorithm_c.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/algorithm_c.dir/main.c.i"
	E:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLionProject\algorithm-c\main.c > CMakeFiles\algorithm_c.dir\main.c.i

CMakeFiles/algorithm_c.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/algorithm_c.dir/main.c.s"
	E:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLionProject\algorithm-c\main.c -o CMakeFiles\algorithm_c.dir\main.c.s

# Object files for target algorithm_c
algorithm_c_OBJECTS = \
"CMakeFiles/algorithm_c.dir/main.c.obj"

# External object files for target algorithm_c
algorithm_c_EXTERNAL_OBJECTS =

algorithm_c.exe: CMakeFiles/algorithm_c.dir/main.c.obj
algorithm_c.exe: CMakeFiles/algorithm_c.dir/build.make
algorithm_c.exe: CMakeFiles/algorithm_c.dir/linklibs.rsp
algorithm_c.exe: CMakeFiles/algorithm_c.dir/objects1.rsp
algorithm_c.exe: CMakeFiles/algorithm_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLionProject\algorithm-c\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable algorithm_c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithm_c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithm_c.dir/build: algorithm_c.exe

.PHONY : CMakeFiles/algorithm_c.dir/build

CMakeFiles/algorithm_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithm_c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algorithm_c.dir/clean

CMakeFiles/algorithm_c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLionProject\algorithm-c E:\CLionProject\algorithm-c E:\CLionProject\algorithm-c\cmake-build-debug E:\CLionProject\algorithm-c\cmake-build-debug E:\CLionProject\algorithm-c\cmake-build-debug\CMakeFiles\algorithm_c.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algorithm_c.dir/depend
