# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\uSeR\Desktop\dotProduct

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\uSeR\Desktop\dotProduct\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dotProduct.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/dotProduct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dotProduct.dir/flags.make

CMakeFiles/dotProduct.dir/dot.c.obj: CMakeFiles/dotProduct.dir/flags.make
CMakeFiles/dotProduct.dir/dot.c.obj: ../dot.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\uSeR\Desktop\dotProduct\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dotProduct.dir/dot.c.obj"
	"D:\Program Files (x86)\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\dotProduct.dir\dot.c.obj -c C:\Users\uSeR\Desktop\dotProduct\dot.c

CMakeFiles/dotProduct.dir/dot.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dotProduct.dir/dot.c.i"
	"D:\Program Files (x86)\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\uSeR\Desktop\dotProduct\dot.c > CMakeFiles\dotProduct.dir\dot.c.i

CMakeFiles/dotProduct.dir/dot.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dotProduct.dir/dot.c.s"
	"D:\Program Files (x86)\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\uSeR\Desktop\dotProduct\dot.c -o CMakeFiles\dotProduct.dir\dot.c.s

# Object files for target dotProduct
dotProduct_OBJECTS = \
"CMakeFiles/dotProduct.dir/dot.c.obj"

# External object files for target dotProduct
dotProduct_EXTERNAL_OBJECTS =

dotProduct.exe: CMakeFiles/dotProduct.dir/dot.c.obj
dotProduct.exe: CMakeFiles/dotProduct.dir/build.make
dotProduct.exe: CMakeFiles/dotProduct.dir/linklibs.rsp
dotProduct.exe: CMakeFiles/dotProduct.dir/objects1.rsp
dotProduct.exe: CMakeFiles/dotProduct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\uSeR\Desktop\dotProduct\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dotProduct.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dotProduct.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dotProduct.dir/build: dotProduct.exe
.PHONY : CMakeFiles/dotProduct.dir/build

CMakeFiles/dotProduct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dotProduct.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dotProduct.dir/clean

CMakeFiles/dotProduct.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\uSeR\Desktop\dotProduct C:\Users\uSeR\Desktop\dotProduct C:\Users\uSeR\Desktop\dotProduct\cmake-build-debug C:\Users\uSeR\Desktop\dotProduct\cmake-build-debug C:\Users\uSeR\Desktop\dotProduct\cmake-build-debug\CMakeFiles\dotProduct.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dotProduct.dir/depend
