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
CMAKE_SOURCE_DIR = "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/Debug"

# Include any dependencies generated for this target.
include CMakeFiles/Infix_to_postfix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Infix_to_postfix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Infix_to_postfix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Infix_to_postfix.dir/flags.make

CMakeFiles/Infix_to_postfix.dir/main.cpp.o: CMakeFiles/Infix_to_postfix.dir/flags.make
CMakeFiles/Infix_to_postfix.dir/main.cpp.o: /home/thoth/Practice\ &\ Projects/C_plus_plus_practice/Infix_to_postfix/main.cpp
CMakeFiles/Infix_to_postfix.dir/main.cpp.o: CMakeFiles/Infix_to_postfix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/Debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Infix_to_postfix.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Infix_to_postfix.dir/main.cpp.o -MF CMakeFiles/Infix_to_postfix.dir/main.cpp.o.d -o CMakeFiles/Infix_to_postfix.dir/main.cpp.o -c "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/main.cpp"

CMakeFiles/Infix_to_postfix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Infix_to_postfix.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/main.cpp" > CMakeFiles/Infix_to_postfix.dir/main.cpp.i

CMakeFiles/Infix_to_postfix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Infix_to_postfix.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/main.cpp" -o CMakeFiles/Infix_to_postfix.dir/main.cpp.s

# Object files for target Infix_to_postfix
Infix_to_postfix_OBJECTS = \
"CMakeFiles/Infix_to_postfix.dir/main.cpp.o"

# External object files for target Infix_to_postfix
Infix_to_postfix_EXTERNAL_OBJECTS =

Infix_to_postfix: CMakeFiles/Infix_to_postfix.dir/main.cpp.o
Infix_to_postfix: CMakeFiles/Infix_to_postfix.dir/build.make
Infix_to_postfix: CMakeFiles/Infix_to_postfix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/Debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Infix_to_postfix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Infix_to_postfix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Infix_to_postfix.dir/build: Infix_to_postfix
.PHONY : CMakeFiles/Infix_to_postfix.dir/build

CMakeFiles/Infix_to_postfix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Infix_to_postfix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Infix_to_postfix.dir/clean

CMakeFiles/Infix_to_postfix.dir/depend:
	cd "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/Debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix" "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix" "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/Debug" "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/Debug" "/home/thoth/Practice & Projects/C_plus_plus_practice/Infix_to_postfix/Debug/CMakeFiles/Infix_to_postfix.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Infix_to_postfix.dir/depend

