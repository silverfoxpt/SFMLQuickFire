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

# Include any dependencies generated for this target.
include CMakeFiles/hellogl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hellogl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hellogl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hellogl.dir/flags.make

CMakeFiles/hellogl.dir/main.cpp.obj: CMakeFiles/hellogl.dir/flags.make
CMakeFiles/hellogl.dir/main.cpp.obj: CMakeFiles/hellogl.dir/includes_CXX.rsp
CMakeFiles/hellogl.dir/main.cpp.obj: D:/SFML\ Projects/SFMLQuickFire/SFMLQuickFire/main.cpp
CMakeFiles/hellogl.dir/main.cpp.obj: CMakeFiles/hellogl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hellogl.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellogl.dir/main.cpp.obj -MF CMakeFiles\hellogl.dir\main.cpp.obj.d -o CMakeFiles\hellogl.dir\main.cpp.obj -c "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\main.cpp"

CMakeFiles/hellogl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellogl.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\main.cpp" > CMakeFiles\hellogl.dir\main.cpp.i

CMakeFiles/hellogl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellogl.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\main.cpp" -o CMakeFiles\hellogl.dir\main.cpp.s

# Object files for target hellogl
hellogl_OBJECTS = \
"CMakeFiles/hellogl.dir/main.cpp.obj"

# External object files for target hellogl
hellogl_EXTERNAL_OBJECTS =

hellogl.exe: CMakeFiles/hellogl.dir/main.cpp.obj
hellogl.exe: CMakeFiles/hellogl.dir/build.make
hellogl.exe: deps/glad/libglad.a
hellogl.exe: deps/glfw-3.4/src/libglfw3.a
hellogl.exe: CMakeFiles/hellogl.dir/linkLibs.rsp
hellogl.exe: CMakeFiles/hellogl.dir/objects1.rsp
hellogl.exe: CMakeFiles/hellogl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hellogl.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hellogl.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hellogl.dir/build: hellogl.exe
.PHONY : CMakeFiles/hellogl.dir/build

CMakeFiles/hellogl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hellogl.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hellogl.dir/clean

CMakeFiles/hellogl.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build" "D:\SFML Projects\SFMLQuickFire\SFMLQuickFire\build\CMakeFiles\hellogl.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/hellogl.dir/depend

