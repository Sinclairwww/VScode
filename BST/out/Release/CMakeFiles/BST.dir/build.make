# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = F:\CMake\bin\cmake.exe

# The command to remove a file.
RM = F:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\VScode\BST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\VScode\BST\out\Release

# Include any dependencies generated for this target.
include CMakeFiles/BST.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BST.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BST.dir/flags.make

CMakeFiles/BST.dir/module.c.obj: CMakeFiles/BST.dir/flags.make
CMakeFiles/BST.dir/module.c.obj: F:/VScode/BST/module.c
CMakeFiles/BST.dir/module.c.obj: CMakeFiles/BST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\VScode\BST\out\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BST.dir/module.c.obj"
	F:\gytx_x86_64-12.1.0-posix-seh\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BST.dir/module.c.obj -MF CMakeFiles\BST.dir\module.c.obj.d -o CMakeFiles\BST.dir\module.c.obj -c F:\VScode\BST\module.c

CMakeFiles/BST.dir/module.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BST.dir/module.c.i"
	F:\gytx_x86_64-12.1.0-posix-seh\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\VScode\BST\module.c > CMakeFiles\BST.dir\module.c.i

CMakeFiles/BST.dir/module.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BST.dir/module.c.s"
	F:\gytx_x86_64-12.1.0-posix-seh\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\VScode\BST\module.c -o CMakeFiles\BST.dir\module.c.s

CMakeFiles/BST.dir/main.c.obj: CMakeFiles/BST.dir/flags.make
CMakeFiles/BST.dir/main.c.obj: F:/VScode/BST/main.c
CMakeFiles/BST.dir/main.c.obj: CMakeFiles/BST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\VScode\BST\out\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BST.dir/main.c.obj"
	F:\gytx_x86_64-12.1.0-posix-seh\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BST.dir/main.c.obj -MF CMakeFiles\BST.dir\main.c.obj.d -o CMakeFiles\BST.dir\main.c.obj -c F:\VScode\BST\main.c

CMakeFiles/BST.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BST.dir/main.c.i"
	F:\gytx_x86_64-12.1.0-posix-seh\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\VScode\BST\main.c > CMakeFiles\BST.dir\main.c.i

CMakeFiles/BST.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BST.dir/main.c.s"
	F:\gytx_x86_64-12.1.0-posix-seh\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\VScode\BST\main.c -o CMakeFiles\BST.dir\main.c.s

# Object files for target BST
BST_OBJECTS = \
"CMakeFiles/BST.dir/module.c.obj" \
"CMakeFiles/BST.dir/main.c.obj"

# External object files for target BST
BST_EXTERNAL_OBJECTS =

BST.exe: CMakeFiles/BST.dir/module.c.obj
BST.exe: CMakeFiles/BST.dir/main.c.obj
BST.exe: CMakeFiles/BST.dir/build.make
BST.exe: CMakeFiles/BST.dir/linkLibs.rsp
BST.exe: CMakeFiles/BST.dir/objects1
BST.exe: CMakeFiles/BST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\VScode\BST\out\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable BST.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BST.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BST.dir/build: BST.exe
.PHONY : CMakeFiles/BST.dir/build

CMakeFiles/BST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BST.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BST.dir/clean

CMakeFiles/BST.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\VScode\BST F:\VScode\BST F:\VScode\BST\out\Release F:\VScode\BST\out\Release F:\VScode\BST\out\Release\CMakeFiles\BST.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BST.dir/depend
