# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/work/game-rogue-sdl/game-rogue-sdl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/game-rogue-sdl/game-rogue-sdl/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/Game.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/game-rogue-sdl/game-rogue-sdl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/Game.cpp.o"
	em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Game.cpp.o -c /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/Game.cpp

CMakeFiles/main.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Game.cpp.i"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/Game.cpp > CMakeFiles/main.dir/src/Game.cpp.i

CMakeFiles/main.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Game.cpp.s"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/Game.cpp -o CMakeFiles/main.dir/src/Game.cpp.s

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/game-rogue-sdl/game-rogue-sdl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/TextureManager.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/TextureManager.cpp.o: ../src/TextureManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/game-rogue-sdl/game-rogue-sdl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/TextureManager.cpp.o"
	em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/TextureManager.cpp.o -c /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/TextureManager.cpp

CMakeFiles/main.dir/src/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/TextureManager.cpp.i"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/TextureManager.cpp > CMakeFiles/main.dir/src/TextureManager.cpp.i

CMakeFiles/main.dir/src/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/TextureManager.cpp.s"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/TextureManager.cpp -o CMakeFiles/main.dir/src/TextureManager.cpp.s

CMakeFiles/main.dir/src/GameObject.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameObject.cpp.o: ../src/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/game-rogue-sdl/game-rogue-sdl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/GameObject.cpp.o"
	em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/GameObject.cpp.o -c /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/GameObject.cpp

CMakeFiles/main.dir/src/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameObject.cpp.i"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/GameObject.cpp > CMakeFiles/main.dir/src/GameObject.cpp.i

CMakeFiles/main.dir/src/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameObject.cpp.s"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/GameObject.cpp -o CMakeFiles/main.dir/src/GameObject.cpp.s

CMakeFiles/main.dir/src/Map.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Map.cpp.o: ../src/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/game-rogue-sdl/game-rogue-sdl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/Map.cpp.o"
	em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Map.cpp.o -c /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/Map.cpp

CMakeFiles/main.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Map.cpp.i"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/Map.cpp > CMakeFiles/main.dir/src/Map.cpp.i

CMakeFiles/main.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Map.cpp.s"
	em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/game-rogue-sdl/game-rogue-sdl/src/Map.cpp -o CMakeFiles/main.dir/src/Map.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/Game.cpp.o" \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/src/TextureManager.cpp.o" \
"CMakeFiles/main.dir/src/GameObject.cpp.o" \
"CMakeFiles/main.dir/src/Map.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.js: CMakeFiles/main.dir/src/Game.cpp.o
main.js: CMakeFiles/main.dir/src/main.cpp.o
main.js: CMakeFiles/main.dir/src/TextureManager.cpp.o
main.js: CMakeFiles/main.dir/src/GameObject.cpp.o
main.js: CMakeFiles/main.dir/src/Map.cpp.o
main.js: CMakeFiles/main.dir/build.make
main.js: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/game-rogue-sdl/game-rogue-sdl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable main.js"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.js

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/runner/work/game-rogue-sdl/game-rogue-sdl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/game-rogue-sdl/game-rogue-sdl /home/runner/work/game-rogue-sdl/game-rogue-sdl /home/runner/work/game-rogue-sdl/game-rogue-sdl/build /home/runner/work/game-rogue-sdl/game-rogue-sdl/build /home/runner/work/game-rogue-sdl/game-rogue-sdl/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

