# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/Debug"

# Include any dependencies generated for this target.
include CMakeFiles/Postfix_evaluation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Postfix_evaluation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Postfix_evaluation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Postfix_evaluation.dir/flags.make

CMakeFiles/Postfix_evaluation.dir/main.cpp.o: CMakeFiles/Postfix_evaluation.dir/flags.make
CMakeFiles/Postfix_evaluation.dir/main.cpp.o: /home/thoth/Practice\ &\ Projects/C_plus_plus_practice/Postfix_evaluation/main.cpp
CMakeFiles/Postfix_evaluation.dir/main.cpp.o: CMakeFiles/Postfix_evaluation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/Debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Postfix_evaluation.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Postfix_evaluation.dir/main.cpp.o -MF CMakeFiles/Postfix_evaluation.dir/main.cpp.o.d -o CMakeFiles/Postfix_evaluation.dir/main.cpp.o -c "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/main.cpp"

CMakeFiles/Postfix_evaluation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Postfix_evaluation.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/main.cpp" > CMakeFiles/Postfix_evaluation.dir/main.cpp.i

CMakeFiles/Postfix_evaluation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Postfix_evaluation.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/main.cpp" -o CMakeFiles/Postfix_evaluation.dir/main.cpp.s

# Object files for target Postfix_evaluation
Postfix_evaluation_OBJECTS = \
"CMakeFiles/Postfix_evaluation.dir/main.cpp.o"

# External object files for target Postfix_evaluation
Postfix_evaluation_EXTERNAL_OBJECTS =

Postfix_evaluation: CMakeFiles/Postfix_evaluation.dir/main.cpp.o
Postfix_evaluation: CMakeFiles/Postfix_evaluation.dir/build.make
Postfix_evaluation: CMakeFiles/Postfix_evaluation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/Debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Postfix_evaluation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Postfix_evaluation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Postfix_evaluation.dir/build: Postfix_evaluation
.PHONY : CMakeFiles/Postfix_evaluation.dir/build

CMakeFiles/Postfix_evaluation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Postfix_evaluation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Postfix_evaluation.dir/clean

CMakeFiles/Postfix_evaluation.dir/depend:
	cd "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/Debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation" "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation" "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/Debug" "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/Debug" "/home/thoth/Practice & Projects/C_plus_plus_practice/Postfix_evaluation/Debug/CMakeFiles/Postfix_evaluation.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Postfix_evaluation.dir/depend

