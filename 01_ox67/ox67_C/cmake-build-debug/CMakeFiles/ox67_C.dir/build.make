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
CMAKE_COMMAND = /home/daniel/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/daniel/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniel/Documents/kattis_practice/01_ox67/ox67_C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ox67_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ox67_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ox67_C.dir/flags.make

CMakeFiles/ox67_C.dir/main.cpp.o: CMakeFiles/ox67_C.dir/flags.make
CMakeFiles/ox67_C.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/Documents/kattis_practice/01_ox67/ox67_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ox67_C.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ox67_C.dir/main.cpp.o -c /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/main.cpp

CMakeFiles/ox67_C.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ox67_C.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/main.cpp > CMakeFiles/ox67_C.dir/main.cpp.i

CMakeFiles/ox67_C.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ox67_C.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/main.cpp -o CMakeFiles/ox67_C.dir/main.cpp.s

CMakeFiles/ox67_C.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ox67_C.dir/main.cpp.o.requires

CMakeFiles/ox67_C.dir/main.cpp.o.provides: CMakeFiles/ox67_C.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ox67_C.dir/build.make CMakeFiles/ox67_C.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ox67_C.dir/main.cpp.o.provides

CMakeFiles/ox67_C.dir/main.cpp.o.provides.build: CMakeFiles/ox67_C.dir/main.cpp.o


# Object files for target ox67_C
ox67_C_OBJECTS = \
"CMakeFiles/ox67_C.dir/main.cpp.o"

# External object files for target ox67_C
ox67_C_EXTERNAL_OBJECTS =

ox67_C: CMakeFiles/ox67_C.dir/main.cpp.o
ox67_C: CMakeFiles/ox67_C.dir/build.make
ox67_C: CMakeFiles/ox67_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniel/Documents/kattis_practice/01_ox67/ox67_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ox67_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ox67_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ox67_C.dir/build: ox67_C

.PHONY : CMakeFiles/ox67_C.dir/build

CMakeFiles/ox67_C.dir/requires: CMakeFiles/ox67_C.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ox67_C.dir/requires

CMakeFiles/ox67_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ox67_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ox67_C.dir/clean

CMakeFiles/ox67_C.dir/depend:
	cd /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniel/Documents/kattis_practice/01_ox67/ox67_C /home/daniel/Documents/kattis_practice/01_ox67/ox67_C /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/cmake-build-debug /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/cmake-build-debug /home/daniel/Documents/kattis_practice/01_ox67/ox67_C/cmake-build-debug/CMakeFiles/ox67_C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ox67_C.dir/depend

