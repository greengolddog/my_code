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
include tests/CMakeFiles/glfwinfo.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/glfwinfo.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/glfwinfo.dir/flags.make

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: /home/greengolddog/my_code/opengl_project/glfw-3.3.3/tests/glfwinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/glfwinfo.c.o -c /home/greengolddog/my_code/opengl_project/glfw-3.3.3/tests/glfwinfo.c

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/glfwinfo.c.i"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greengolddog/my_code/opengl_project/glfw-3.3.3/tests/glfwinfo.c > CMakeFiles/glfwinfo.dir/glfwinfo.c.i

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/glfwinfo.c.s"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greengolddog/my_code/opengl_project/glfw-3.3.3/tests/glfwinfo.c -o CMakeFiles/glfwinfo.dir/glfwinfo.c.s

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o -c /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/getopt.c

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/getopt.c > CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/getopt.c -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o -c /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c > CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_gl.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o -c /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_vulkan.c

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_vulkan.c > CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s"
	cd /home/greengolddog/my_code/opengl_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greengolddog/my_code/opengl_project/glfw-3.3.3/deps/glad_vulkan.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s

# Object files for target glfwinfo
glfwinfo_OBJECTS = \
"CMakeFiles/glfwinfo.dir/glfwinfo.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"

# External object files for target glfwinfo
glfwinfo_EXTERNAL_OBJECTS =

tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/build.make
tests/glfwinfo: src/libglfw3.a
tests/glfwinfo: /usr/lib/libm.so
tests/glfwinfo: /usr/lib/librt.so
tests/glfwinfo: /usr/lib/libm.so
tests/glfwinfo: /usr/lib/libX11.so
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/greengolddog/my_code/opengl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable glfwinfo"
	cd /home/greengolddog/my_code/opengl_project/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfwinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/glfwinfo.dir/build: tests/glfwinfo

.PHONY : tests/CMakeFiles/glfwinfo.dir/build

tests/CMakeFiles/glfwinfo.dir/clean:
	cd /home/greengolddog/my_code/opengl_project/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/glfwinfo.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/glfwinfo.dir/clean

tests/CMakeFiles/glfwinfo.dir/depend:
	cd /home/greengolddog/my_code/opengl_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/greengolddog/my_code/opengl_project/glfw-3.3.3 /home/greengolddog/my_code/opengl_project/glfw-3.3.3/tests /home/greengolddog/my_code/opengl_project/build /home/greengolddog/my_code/opengl_project/build/tests /home/greengolddog/my_code/opengl_project/build/tests/CMakeFiles/glfwinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/glfwinfo.dir/depend

