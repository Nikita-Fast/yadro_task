# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/fastmi/projects/yadro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fastmi/projects/yadro/build

# Include any dependencies generated for this target.
include CMakeFiles/yadro_task.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/yadro_task.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/yadro_task.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yadro_task.dir/flags.make

CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o: CMakeFiles/yadro_task.dir/flags.make
CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o: ../src/awgn_channel.cpp
CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o: CMakeFiles/yadro_task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmi/projects/yadro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o -MF CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o.d -o CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o -c /home/fastmi/projects/yadro/src/awgn_channel.cpp

CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmi/projects/yadro/src/awgn_channel.cpp > CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.i

CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmi/projects/yadro/src/awgn_channel.cpp -o CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.s

CMakeFiles/yadro_task.dir/src/main.cpp.o: CMakeFiles/yadro_task.dir/flags.make
CMakeFiles/yadro_task.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/yadro_task.dir/src/main.cpp.o: CMakeFiles/yadro_task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmi/projects/yadro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/yadro_task.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yadro_task.dir/src/main.cpp.o -MF CMakeFiles/yadro_task.dir/src/main.cpp.o.d -o CMakeFiles/yadro_task.dir/src/main.cpp.o -c /home/fastmi/projects/yadro/src/main.cpp

CMakeFiles/yadro_task.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yadro_task.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmi/projects/yadro/src/main.cpp > CMakeFiles/yadro_task.dir/src/main.cpp.i

CMakeFiles/yadro_task.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yadro_task.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmi/projects/yadro/src/main.cpp -o CMakeFiles/yadro_task.dir/src/main.cpp.s

CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o: CMakeFiles/yadro_task.dir/flags.make
CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o: ../src/qam_demodulator.cpp
CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o: CMakeFiles/yadro_task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmi/projects/yadro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o -MF CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o.d -o CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o -c /home/fastmi/projects/yadro/src/qam_demodulator.cpp

CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmi/projects/yadro/src/qam_demodulator.cpp > CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.i

CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmi/projects/yadro/src/qam_demodulator.cpp -o CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.s

CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o: CMakeFiles/yadro_task.dir/flags.make
CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o: ../src/qam_modulator.cpp
CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o: CMakeFiles/yadro_task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmi/projects/yadro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o -MF CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o.d -o CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o -c /home/fastmi/projects/yadro/src/qam_modulator.cpp

CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmi/projects/yadro/src/qam_modulator.cpp > CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.i

CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmi/projects/yadro/src/qam_modulator.cpp -o CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.s

# Object files for target yadro_task
yadro_task_OBJECTS = \
"CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o" \
"CMakeFiles/yadro_task.dir/src/main.cpp.o" \
"CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o" \
"CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o"

# External object files for target yadro_task
yadro_task_EXTERNAL_OBJECTS =

yadro_task: CMakeFiles/yadro_task.dir/src/awgn_channel.cpp.o
yadro_task: CMakeFiles/yadro_task.dir/src/main.cpp.o
yadro_task: CMakeFiles/yadro_task.dir/src/qam_demodulator.cpp.o
yadro_task: CMakeFiles/yadro_task.dir/src/qam_modulator.cpp.o
yadro_task: CMakeFiles/yadro_task.dir/build.make
yadro_task: /usr/lib/python3.10/config-3.10-x86_64-linux-gnu/libpython3.10.so
yadro_task: CMakeFiles/yadro_task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fastmi/projects/yadro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable yadro_task"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yadro_task.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yadro_task.dir/build: yadro_task
.PHONY : CMakeFiles/yadro_task.dir/build

CMakeFiles/yadro_task.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yadro_task.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yadro_task.dir/clean

CMakeFiles/yadro_task.dir/depend:
	cd /home/fastmi/projects/yadro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fastmi/projects/yadro /home/fastmi/projects/yadro /home/fastmi/projects/yadro/build /home/fastmi/projects/yadro/build /home/fastmi/projects/yadro/build/CMakeFiles/yadro_task.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yadro_task.dir/depend
