# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/solve_maze.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/solve_maze.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/solve_maze.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/solve_maze.dir/flags.make

CMakeFiles/solve_maze.dir/src/main.cpp.obj: CMakeFiles/solve_maze.dir/flags.make
CMakeFiles/solve_maze.dir/src/main.cpp.obj: C:/Users/heral/School/CPP/Assignments/assignment-2-w0468787/src/main.cpp
CMakeFiles/solve_maze.dir/src/main.cpp.obj: CMakeFiles/solve_maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/solve_maze.dir/src/main.cpp.obj"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/solve_maze.dir/src/main.cpp.obj -MF CMakeFiles\solve_maze.dir\src\main.cpp.obj.d -o CMakeFiles\solve_maze.dir\src\main.cpp.obj -c C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\main.cpp

CMakeFiles/solve_maze.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solve_maze.dir/src/main.cpp.i"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\main.cpp > CMakeFiles\solve_maze.dir\src\main.cpp.i

CMakeFiles/solve_maze.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solve_maze.dir/src/main.cpp.s"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\main.cpp -o CMakeFiles\solve_maze.dir\src\main.cpp.s

CMakeFiles/solve_maze.dir/src/queue.cpp.obj: CMakeFiles/solve_maze.dir/flags.make
CMakeFiles/solve_maze.dir/src/queue.cpp.obj: C:/Users/heral/School/CPP/Assignments/assignment-2-w0468787/src/queue.cpp
CMakeFiles/solve_maze.dir/src/queue.cpp.obj: CMakeFiles/solve_maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/solve_maze.dir/src/queue.cpp.obj"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/solve_maze.dir/src/queue.cpp.obj -MF CMakeFiles\solve_maze.dir\src\queue.cpp.obj.d -o CMakeFiles\solve_maze.dir\src\queue.cpp.obj -c C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\queue.cpp

CMakeFiles/solve_maze.dir/src/queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solve_maze.dir/src/queue.cpp.i"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\queue.cpp > CMakeFiles\solve_maze.dir\src\queue.cpp.i

CMakeFiles/solve_maze.dir/src/queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solve_maze.dir/src/queue.cpp.s"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\queue.cpp -o CMakeFiles\solve_maze.dir\src\queue.cpp.s

CMakeFiles/solve_maze.dir/src/maze_solver.cpp.obj: CMakeFiles/solve_maze.dir/flags.make
CMakeFiles/solve_maze.dir/src/maze_solver.cpp.obj: C:/Users/heral/School/CPP/Assignments/assignment-2-w0468787/src/maze_solver.cpp
CMakeFiles/solve_maze.dir/src/maze_solver.cpp.obj: CMakeFiles/solve_maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/solve_maze.dir/src/maze_solver.cpp.obj"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/solve_maze.dir/src/maze_solver.cpp.obj -MF CMakeFiles\solve_maze.dir\src\maze_solver.cpp.obj.d -o CMakeFiles\solve_maze.dir\src\maze_solver.cpp.obj -c C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\maze_solver.cpp

CMakeFiles/solve_maze.dir/src/maze_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solve_maze.dir/src/maze_solver.cpp.i"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\maze_solver.cpp > CMakeFiles\solve_maze.dir\src\maze_solver.cpp.i

CMakeFiles/solve_maze.dir/src/maze_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solve_maze.dir/src/maze_solver.cpp.s"
	C:\Users\heral\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9921.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\src\maze_solver.cpp -o CMakeFiles\solve_maze.dir\src\maze_solver.cpp.s

# Object files for target solve_maze
solve_maze_OBJECTS = \
"CMakeFiles/solve_maze.dir/src/main.cpp.obj" \
"CMakeFiles/solve_maze.dir/src/queue.cpp.obj" \
"CMakeFiles/solve_maze.dir/src/maze_solver.cpp.obj"

# External object files for target solve_maze
solve_maze_EXTERNAL_OBJECTS =

solve_maze.exe: CMakeFiles/solve_maze.dir/src/main.cpp.obj
solve_maze.exe: CMakeFiles/solve_maze.dir/src/queue.cpp.obj
solve_maze.exe: CMakeFiles/solve_maze.dir/src/maze_solver.cpp.obj
solve_maze.exe: CMakeFiles/solve_maze.dir/build.make
solve_maze.exe: CMakeFiles/solve_maze.dir/linkLibs.rsp
solve_maze.exe: CMakeFiles/solve_maze.dir/objects1.rsp
solve_maze.exe: CMakeFiles/solve_maze.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable solve_maze.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\solve_maze.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/solve_maze.dir/build: solve_maze.exe
.PHONY : CMakeFiles/solve_maze.dir/build

CMakeFiles/solve_maze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\solve_maze.dir\cmake_clean.cmake
.PHONY : CMakeFiles/solve_maze.dir/clean

CMakeFiles/solve_maze.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787 C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787 C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug C:\Users\heral\School\CPP\Assignments\assignment-2-w0468787\cmake-build-debug\CMakeFiles\Solve_Maze.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/solve_maze.dir/depend

