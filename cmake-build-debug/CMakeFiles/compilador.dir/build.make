# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/thiago/Software/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/thiago/Software/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thiago/Documents/CLionProjects/compilador

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thiago/Documents/CLionProjects/compilador/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/compilador.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/compilador.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/compilador.dir/flags.make

CMakeFiles/compilador.dir/main.cpp.o: CMakeFiles/compilador.dir/flags.make
CMakeFiles/compilador.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiago/Documents/CLionProjects/compilador/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/compilador.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compilador.dir/main.cpp.o -c /home/thiago/Documents/CLionProjects/compilador/main.cpp

CMakeFiles/compilador.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compilador.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thiago/Documents/CLionProjects/compilador/main.cpp > CMakeFiles/compilador.dir/main.cpp.i

CMakeFiles/compilador.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compilador.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thiago/Documents/CLionProjects/compilador/main.cpp -o CMakeFiles/compilador.dir/main.cpp.s

CMakeFiles/compilador.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/compilador.dir/main.cpp.o.requires

CMakeFiles/compilador.dir/main.cpp.o.provides: CMakeFiles/compilador.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/compilador.dir/build.make CMakeFiles/compilador.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/compilador.dir/main.cpp.o.provides

CMakeFiles/compilador.dir/main.cpp.o.provides.build: CMakeFiles/compilador.dir/main.cpp.o


CMakeFiles/compilador.dir/Lexico.cpp.o: CMakeFiles/compilador.dir/flags.make
CMakeFiles/compilador.dir/Lexico.cpp.o: ../Lexico.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiago/Documents/CLionProjects/compilador/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/compilador.dir/Lexico.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compilador.dir/Lexico.cpp.o -c /home/thiago/Documents/CLionProjects/compilador/Lexico.cpp

CMakeFiles/compilador.dir/Lexico.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compilador.dir/Lexico.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thiago/Documents/CLionProjects/compilador/Lexico.cpp > CMakeFiles/compilador.dir/Lexico.cpp.i

CMakeFiles/compilador.dir/Lexico.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compilador.dir/Lexico.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thiago/Documents/CLionProjects/compilador/Lexico.cpp -o CMakeFiles/compilador.dir/Lexico.cpp.s

CMakeFiles/compilador.dir/Lexico.cpp.o.requires:

.PHONY : CMakeFiles/compilador.dir/Lexico.cpp.o.requires

CMakeFiles/compilador.dir/Lexico.cpp.o.provides: CMakeFiles/compilador.dir/Lexico.cpp.o.requires
	$(MAKE) -f CMakeFiles/compilador.dir/build.make CMakeFiles/compilador.dir/Lexico.cpp.o.provides.build
.PHONY : CMakeFiles/compilador.dir/Lexico.cpp.o.provides

CMakeFiles/compilador.dir/Lexico.cpp.o.provides.build: CMakeFiles/compilador.dir/Lexico.cpp.o


CMakeFiles/compilador.dir/Sintatico.cpp.o: CMakeFiles/compilador.dir/flags.make
CMakeFiles/compilador.dir/Sintatico.cpp.o: ../Sintatico.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiago/Documents/CLionProjects/compilador/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/compilador.dir/Sintatico.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compilador.dir/Sintatico.cpp.o -c /home/thiago/Documents/CLionProjects/compilador/Sintatico.cpp

CMakeFiles/compilador.dir/Sintatico.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compilador.dir/Sintatico.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thiago/Documents/CLionProjects/compilador/Sintatico.cpp > CMakeFiles/compilador.dir/Sintatico.cpp.i

CMakeFiles/compilador.dir/Sintatico.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compilador.dir/Sintatico.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thiago/Documents/CLionProjects/compilador/Sintatico.cpp -o CMakeFiles/compilador.dir/Sintatico.cpp.s

CMakeFiles/compilador.dir/Sintatico.cpp.o.requires:

.PHONY : CMakeFiles/compilador.dir/Sintatico.cpp.o.requires

CMakeFiles/compilador.dir/Sintatico.cpp.o.provides: CMakeFiles/compilador.dir/Sintatico.cpp.o.requires
	$(MAKE) -f CMakeFiles/compilador.dir/build.make CMakeFiles/compilador.dir/Sintatico.cpp.o.provides.build
.PHONY : CMakeFiles/compilador.dir/Sintatico.cpp.o.provides

CMakeFiles/compilador.dir/Sintatico.cpp.o.provides.build: CMakeFiles/compilador.dir/Sintatico.cpp.o


# Object files for target compilador
compilador_OBJECTS = \
"CMakeFiles/compilador.dir/main.cpp.o" \
"CMakeFiles/compilador.dir/Lexico.cpp.o" \
"CMakeFiles/compilador.dir/Sintatico.cpp.o"

# External object files for target compilador
compilador_EXTERNAL_OBJECTS =

compilador: CMakeFiles/compilador.dir/main.cpp.o
compilador: CMakeFiles/compilador.dir/Lexico.cpp.o
compilador: CMakeFiles/compilador.dir/Sintatico.cpp.o
compilador: CMakeFiles/compilador.dir/build.make
compilador: CMakeFiles/compilador.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thiago/Documents/CLionProjects/compilador/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable compilador"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compilador.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/compilador.dir/build: compilador

.PHONY : CMakeFiles/compilador.dir/build

CMakeFiles/compilador.dir/requires: CMakeFiles/compilador.dir/main.cpp.o.requires
CMakeFiles/compilador.dir/requires: CMakeFiles/compilador.dir/Lexico.cpp.o.requires
CMakeFiles/compilador.dir/requires: CMakeFiles/compilador.dir/Sintatico.cpp.o.requires

.PHONY : CMakeFiles/compilador.dir/requires

CMakeFiles/compilador.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/compilador.dir/cmake_clean.cmake
.PHONY : CMakeFiles/compilador.dir/clean

CMakeFiles/compilador.dir/depend:
	cd /home/thiago/Documents/CLionProjects/compilador/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thiago/Documents/CLionProjects/compilador /home/thiago/Documents/CLionProjects/compilador /home/thiago/Documents/CLionProjects/compilador/cmake-build-debug /home/thiago/Documents/CLionProjects/compilador/cmake-build-debug /home/thiago/Documents/CLionProjects/compilador/cmake-build-debug/CMakeFiles/compilador.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/compilador.dir/depend

