# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dirision\Documents\GitHub\Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dirision\Documents\GitHub\Game\build

# Include any dependencies generated for this target.
include CMakeFiles/Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game.dir/flags.make

CMakeFiles/Game.dir/src/default.cpp.obj: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/src/default.cpp.obj: CMakeFiles/Game.dir/includes_CXX.rsp
CMakeFiles/Game.dir/src/default.cpp.obj: ../src/default.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dirision\Documents\GitHub\Game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game.dir/src/default.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Game.dir\src\default.cpp.obj -c C:\Users\dirision\Documents\GitHub\Game\src\default.cpp

CMakeFiles/Game.dir/src/default.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/src/default.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dirision\Documents\GitHub\Game\src\default.cpp > CMakeFiles\Game.dir\src\default.cpp.i

CMakeFiles/Game.dir/src/default.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/src/default.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dirision\Documents\GitHub\Game\src\default.cpp -o CMakeFiles\Game.dir\src\default.cpp.s

CMakeFiles/Game.dir/src/main.cpp.obj: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/src/main.cpp.obj: CMakeFiles/Game.dir/includes_CXX.rsp
CMakeFiles/Game.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dirision\Documents\GitHub\Game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game.dir/src/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Game.dir\src\main.cpp.obj -c C:\Users\dirision\Documents\GitHub\Game\src\main.cpp

CMakeFiles/Game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/src/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dirision\Documents\GitHub\Game\src\main.cpp > CMakeFiles\Game.dir\src\main.cpp.i

CMakeFiles/Game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/src/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dirision\Documents\GitHub\Game\src\main.cpp -o CMakeFiles\Game.dir\src\main.cpp.s

# Object files for target Game
Game_OBJECTS = \
"CMakeFiles/Game.dir/src/default.cpp.obj" \
"CMakeFiles/Game.dir/src/main.cpp.obj"

# External object files for target Game
Game_EXTERNAL_OBJECTS =

Game.exe: CMakeFiles/Game.dir/src/default.cpp.obj
Game.exe: CMakeFiles/Game.dir/src/main.cpp.obj
Game.exe: CMakeFiles/Game.dir/build.make
Game.exe: lib/Engine/libEngine.dll.a
Game.exe: lib/PAM/libPAM.dll.a
Game.exe: CMakeFiles/Game.dir/linklibs.rsp
Game.exe: CMakeFiles/Game.dir/objects1.rsp
Game.exe: CMakeFiles/Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dirision\Documents\GitHub\Game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game.dir/build: Game.exe

.PHONY : CMakeFiles/Game.dir/build

CMakeFiles/Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Game.dir/clean

CMakeFiles/Game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dirision\Documents\GitHub\Game C:\Users\dirision\Documents\GitHub\Game C:\Users\dirision\Documents\GitHub\Game\build C:\Users\dirision\Documents\GitHub\Game\build C:\Users\dirision\Documents\GitHub\Game\build\CMakeFiles\Game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game.dir/depend

