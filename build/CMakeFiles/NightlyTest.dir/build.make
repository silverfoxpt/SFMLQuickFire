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
CMAKE_COMMAND = D:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = D:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build"

# Utility rule file for NightlyTest.

# Include any custom commands dependencies for this target.
include CMakeFiles/NightlyTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NightlyTest.dir/progress.make

CMakeFiles/NightlyTest:
	D:\mingw64\bin\ctest.exe -D NightlyTest

NightlyTest: CMakeFiles/NightlyTest
NightlyTest: CMakeFiles/NightlyTest.dir/build.make
.PHONY : NightlyTest

# Rule to build all files generated by this target.
CMakeFiles/NightlyTest.dir/build: NightlyTest
.PHONY : CMakeFiles/NightlyTest.dir/build

CMakeFiles/NightlyTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NightlyTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NightlyTest.dir/clean

CMakeFiles/NightlyTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build\CMakeFiles\NightlyTest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NightlyTest.dir/depend

