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
include lib/PAM/CMakeFiles/PAM.dir/depend.make

# Include the progress variables for this target.
include lib/PAM/CMakeFiles/PAM.dir/progress.make

# Include the compile flags for this target's objects.
include lib/PAM/CMakeFiles/PAM.dir/flags.make

lib/PAM/CMakeFiles/PAM.dir/src/PAM.cpp.obj: lib/PAM/CMakeFiles/PAM.dir/flags.make
lib/PAM/CMakeFiles/PAM.dir/src/PAM.cpp.obj: lib/PAM/CMakeFiles/PAM.dir/includes_CXX.rsp
lib/PAM/CMakeFiles/PAM.dir/src/PAM.cpp.obj: ../lib/PAM/src/PAM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dirision\Documents\GitHub\Game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/PAM/CMakeFiles/PAM.dir/src/PAM.cpp.obj"
	cd /d C:\Users\dirision\Documents\GitHub\Game\build\lib\PAM && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PAM.dir\src\PAM.cpp.obj -c C:\Users\dirision\Documents\GitHub\Game\lib\PAM\src\PAM.cpp

lib/PAM/CMakeFiles/PAM.dir/src/PAM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PAM.dir/src/PAM.cpp.i"
	cd /d C:\Users\dirision\Documents\GitHub\Game\build\lib\PAM && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dirision\Documents\GitHub\Game\lib\PAM\src\PAM.cpp > CMakeFiles\PAM.dir\src\PAM.cpp.i

lib/PAM/CMakeFiles/PAM.dir/src/PAM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PAM.dir/src/PAM.cpp.s"
	cd /d C:\Users\dirision\Documents\GitHub\Game\build\lib\PAM && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dirision\Documents\GitHub\Game\lib\PAM\src\PAM.cpp -o CMakeFiles\PAM.dir\src\PAM.cpp.s

# Object files for target PAM
PAM_OBJECTS = \
"CMakeFiles/PAM.dir/src/PAM.cpp.obj"

# External object files for target PAM
PAM_EXTERNAL_OBJECTS =

libPAM.dll: lib/PAM/CMakeFiles/PAM.dir/src/PAM.cpp.obj
libPAM.dll: lib/PAM/CMakeFiles/PAM.dir/build.make
libPAM.dll: lib/PAM/CMakeFiles/PAM.dir/linklibs.rsp
libPAM.dll: lib/PAM/CMakeFiles/PAM.dir/objects1.rsp
libPAM.dll: lib/PAM/CMakeFiles/PAM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dirision\Documents\GitHub\Game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ..\..\libPAM.dll"
	cd /d C:\Users\dirision\Documents\GitHub\Game\build\lib\PAM && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PAM.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/PAM/CMakeFiles/PAM.dir/build: libPAM.dll

.PHONY : lib/PAM/CMakeFiles/PAM.dir/build

lib/PAM/CMakeFiles/PAM.dir/clean:
	cd /d C:\Users\dirision\Documents\GitHub\Game\build\lib\PAM && $(CMAKE_COMMAND) -P CMakeFiles\PAM.dir\cmake_clean.cmake
.PHONY : lib/PAM/CMakeFiles/PAM.dir/clean

lib/PAM/CMakeFiles/PAM.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dirision\Documents\GitHub\Game C:\Users\dirision\Documents\GitHub\Game\lib\PAM C:\Users\dirision\Documents\GitHub\Game\build C:\Users\dirision\Documents\GitHub\Game\build\lib\PAM C:\Users\dirision\Documents\GitHub\Game\build\lib\PAM\CMakeFiles\PAM.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/PAM/CMakeFiles/PAM.dir/depend

