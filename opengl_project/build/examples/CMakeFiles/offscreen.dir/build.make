# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/greengolddog/my_code/opengl_project/glfw-3.3.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/greengolddog/my_code/opengl_project/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/offscreen.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/offscreen.dir/flags.make

examples/CMakeFiles/offscreen.dir/offscreen.c.o: examples/CMakeFiles/offscreen.dir/flags.make
examples/CMakeFiles/offscreen.dir/offscreen.c.o: /home/greengolddog/my_code/opengl_project/glfw-3.3.3/examples/offscreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/offscreen.dir/offscreen.c.o"
	cd /home/greengolddog/my_code/opengl_project/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/offscreen.c.o -c /home/greengolddog/my_code/opengl_project/glfw-3.3.3/examples/offscreen.c

examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd /home/greengolddog/my_code/opengl_project/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greengolddog/my_code/opengl_project/glfw-3.3.3/examples/offscreen.c > CMakeFiles/offscreen.dir/offscreen.c.i

examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd /home/greengolddog/my_code/opengl_project/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greengolddog/my_code/opengl_project/glfw-3.3.3/examples/offscreen.c -o CMakeFiles/offscreen.dir/offscreen.c.s

examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: examples/CMakeFiles/offscreen.dir/flags.make
examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"
	cd /home/greengolddog/my_code/opengl_project/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o -c /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c

examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd /home/greengolddog/my_code/opengl_project/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c > CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i

examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd /home/greengolddog/my_code/opengl_project/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s

# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.o" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

examples/offscreen: examples/CMakeFiles/offscreen.dir/offscreen.c.o
examples/offscreen: examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o
examples/offscreen: examples/CMakeFiles/offscreen.dir/build.make
examples/offscreen: src/libglfw3.a
examples/offscreen: /usr/lib/libm.so
examples/offscreen: /usr/lib/librt.so
examples/offscreen: /usr/lib/libm.so
examples/offscreen: /usr/lib/libX11.so
examples/offscreen: examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable offscreen"
	cd /home/greengolddog/my_code/opengl_project/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offscreen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/offscreen.dir/build: examples/offscreen

.PHONY : examples/CMakeFiles/offscreen.dir/build

examples/CMakeFiles/offscreen.dir/clean:
	cd /home/greengolddog/my_code/opengl_project/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/offscreen.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/offscreen.dir/clean

examples/CMakeFiles/offscreen.dir/depend:
	cd /home/greengolddog/my_code/opengl_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/greengolddog/my_code/opengl_project/glfw-3.3.3 /home/greengolddog/my_code/opengl_project/glfw-3.3.3/examples /home/greengolddog/my_code/opengl_project/build /home/greengolddog/my_code/opengl_project/build/examples /home/greengolddog/my_code/opengl_project/build/examples/CMakeFiles/offscreen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/offscreen.dir/depend

