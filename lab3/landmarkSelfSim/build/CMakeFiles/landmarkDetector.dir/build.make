# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /projects/ros/surfer-main/lab3/landmarkSelfSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /projects/ros/surfer-main/lab3/landmarkSelfSim/build

# Include any dependencies generated for this target.
include CMakeFiles/landmarkDetector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/landmarkDetector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/landmarkDetector.dir/flags.make

CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: CMakeFiles/landmarkDetector.dir/flags.make
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: ../src/landmarkDetector.cpp
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: ../manifest.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/cpp_common/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/rostime/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/rosconsole/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/roscpp_traits/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/roscpp_serialization/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/genmsg/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/genpy/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/message_runtime/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/std_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/rosgraph_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/xmlrpcpp/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/roscpp/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/message_filters/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/console_bridge/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/class_loader/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/catkin/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/rospack/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/roslib/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/pluginlib/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/geometry_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/sensor_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/image_transport/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/diagnostic_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/diagnostic_updater/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/self_test/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/camera_calibration_parsers/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/camera_info_manager/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/usb_cam/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/opencv2/package.xml
CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o: /opt/ros/groovy/share/cv_bridge/package.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /projects/ros/surfer-main/lab3/landmarkSelfSim/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o -c /projects/ros/surfer-main/lab3/landmarkSelfSim/src/landmarkDetector.cpp

CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /projects/ros/surfer-main/lab3/landmarkSelfSim/src/landmarkDetector.cpp > CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.i

CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /projects/ros/surfer-main/lab3/landmarkSelfSim/src/landmarkDetector.cpp -o CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.s

CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.requires:
.PHONY : CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.requires

CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.provides: CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.requires
	$(MAKE) -f CMakeFiles/landmarkDetector.dir/build.make CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.provides.build
.PHONY : CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.provides

CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.provides.build: CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o

CMakeFiles/landmarkDetector.dir/src/barcode.c.o: CMakeFiles/landmarkDetector.dir/flags.make
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: ../src/barcode.c
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: ../manifest.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/cpp_common/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/rostime/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/rosconsole/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/roscpp_traits/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/roscpp_serialization/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/genmsg/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/genpy/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/message_runtime/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/std_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/rosgraph_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/xmlrpcpp/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/roscpp/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/message_filters/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/console_bridge/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/class_loader/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/catkin/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/rospack/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/roslib/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/pluginlib/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/geometry_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/sensor_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/image_transport/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/diagnostic_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/diagnostic_updater/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/self_test/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/camera_calibration_parsers/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/camera_info_manager/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/usb_cam/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/opencv2/package.xml
CMakeFiles/landmarkDetector.dir/src/barcode.c.o: /opt/ros/groovy/share/cv_bridge/package.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /projects/ros/surfer-main/lab3/landmarkSelfSim/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/landmarkDetector.dir/src/barcode.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/landmarkDetector.dir/src/barcode.c.o   -c /projects/ros/surfer-main/lab3/landmarkSelfSim/src/barcode.c

CMakeFiles/landmarkDetector.dir/src/barcode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/landmarkDetector.dir/src/barcode.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /projects/ros/surfer-main/lab3/landmarkSelfSim/src/barcode.c > CMakeFiles/landmarkDetector.dir/src/barcode.c.i

CMakeFiles/landmarkDetector.dir/src/barcode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/landmarkDetector.dir/src/barcode.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /projects/ros/surfer-main/lab3/landmarkSelfSim/src/barcode.c -o CMakeFiles/landmarkDetector.dir/src/barcode.c.s

CMakeFiles/landmarkDetector.dir/src/barcode.c.o.requires:
.PHONY : CMakeFiles/landmarkDetector.dir/src/barcode.c.o.requires

CMakeFiles/landmarkDetector.dir/src/barcode.c.o.provides: CMakeFiles/landmarkDetector.dir/src/barcode.c.o.requires
	$(MAKE) -f CMakeFiles/landmarkDetector.dir/build.make CMakeFiles/landmarkDetector.dir/src/barcode.c.o.provides.build
.PHONY : CMakeFiles/landmarkDetector.dir/src/barcode.c.o.provides

CMakeFiles/landmarkDetector.dir/src/barcode.c.o.provides.build: CMakeFiles/landmarkDetector.dir/src/barcode.c.o

CMakeFiles/landmarkDetector.dir/src/digits.c.o: CMakeFiles/landmarkDetector.dir/flags.make
CMakeFiles/landmarkDetector.dir/src/digits.c.o: ../src/digits.c
CMakeFiles/landmarkDetector.dir/src/digits.c.o: ../manifest.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/cpp_common/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/rostime/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/rosconsole/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/roscpp_traits/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/roscpp_serialization/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/genmsg/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/genpy/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/message_runtime/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/std_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/rosgraph_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/xmlrpcpp/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/roscpp/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/message_filters/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/console_bridge/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/class_loader/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/catkin/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/rospack/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/roslib/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/pluginlib/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/geometry_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/sensor_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/image_transport/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/diagnostic_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/diagnostic_updater/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/self_test/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/camera_calibration_parsers/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/camera_info_manager/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/usb_cam/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/opencv2/package.xml
CMakeFiles/landmarkDetector.dir/src/digits.c.o: /opt/ros/groovy/share/cv_bridge/package.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /projects/ros/surfer-main/lab3/landmarkSelfSim/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/landmarkDetector.dir/src/digits.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/landmarkDetector.dir/src/digits.c.o   -c /projects/ros/surfer-main/lab3/landmarkSelfSim/src/digits.c

CMakeFiles/landmarkDetector.dir/src/digits.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/landmarkDetector.dir/src/digits.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /projects/ros/surfer-main/lab3/landmarkSelfSim/src/digits.c > CMakeFiles/landmarkDetector.dir/src/digits.c.i

CMakeFiles/landmarkDetector.dir/src/digits.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/landmarkDetector.dir/src/digits.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /projects/ros/surfer-main/lab3/landmarkSelfSim/src/digits.c -o CMakeFiles/landmarkDetector.dir/src/digits.c.s

CMakeFiles/landmarkDetector.dir/src/digits.c.o.requires:
.PHONY : CMakeFiles/landmarkDetector.dir/src/digits.c.o.requires

CMakeFiles/landmarkDetector.dir/src/digits.c.o.provides: CMakeFiles/landmarkDetector.dir/src/digits.c.o.requires
	$(MAKE) -f CMakeFiles/landmarkDetector.dir/build.make CMakeFiles/landmarkDetector.dir/src/digits.c.o.provides.build
.PHONY : CMakeFiles/landmarkDetector.dir/src/digits.c.o.provides

CMakeFiles/landmarkDetector.dir/src/digits.c.o.provides.build: CMakeFiles/landmarkDetector.dir/src/digits.c.o

CMakeFiles/landmarkDetector.dir/src/landmark.c.o: CMakeFiles/landmarkDetector.dir/flags.make
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: ../src/landmark.c
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: ../manifest.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/cpp_common/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/rostime/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/rosconsole/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/roscpp_traits/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/roscpp_serialization/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/genmsg/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/genpy/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/message_runtime/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/std_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/rosgraph_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/xmlrpcpp/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/roscpp/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/message_filters/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/console_bridge/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/class_loader/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/catkin/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/rospack/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/roslib/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/pluginlib/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/geometry_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/sensor_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/image_transport/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/diagnostic_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/diagnostic_updater/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/self_test/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/camera_calibration_parsers/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/camera_info_manager/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/usb_cam/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/opencv2/package.xml
CMakeFiles/landmarkDetector.dir/src/landmark.c.o: /opt/ros/groovy/share/cv_bridge/package.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /projects/ros/surfer-main/lab3/landmarkSelfSim/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/landmarkDetector.dir/src/landmark.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/landmarkDetector.dir/src/landmark.c.o   -c /projects/ros/surfer-main/lab3/landmarkSelfSim/src/landmark.c

CMakeFiles/landmarkDetector.dir/src/landmark.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/landmarkDetector.dir/src/landmark.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /projects/ros/surfer-main/lab3/landmarkSelfSim/src/landmark.c > CMakeFiles/landmarkDetector.dir/src/landmark.c.i

CMakeFiles/landmarkDetector.dir/src/landmark.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/landmarkDetector.dir/src/landmark.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /projects/ros/surfer-main/lab3/landmarkSelfSim/src/landmark.c -o CMakeFiles/landmarkDetector.dir/src/landmark.c.s

CMakeFiles/landmarkDetector.dir/src/landmark.c.o.requires:
.PHONY : CMakeFiles/landmarkDetector.dir/src/landmark.c.o.requires

CMakeFiles/landmarkDetector.dir/src/landmark.c.o.provides: CMakeFiles/landmarkDetector.dir/src/landmark.c.o.requires
	$(MAKE) -f CMakeFiles/landmarkDetector.dir/build.make CMakeFiles/landmarkDetector.dir/src/landmark.c.o.provides.build
.PHONY : CMakeFiles/landmarkDetector.dir/src/landmark.c.o.provides

CMakeFiles/landmarkDetector.dir/src/landmark.c.o.provides.build: CMakeFiles/landmarkDetector.dir/src/landmark.c.o

CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: CMakeFiles/landmarkDetector.dir/flags.make
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: ../src/mcimg.c
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: ../manifest.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/cpp_common/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/rostime/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/rosconsole/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/roscpp_traits/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/roscpp_serialization/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/genmsg/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/genpy/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/message_runtime/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/std_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/rosgraph_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/xmlrpcpp/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/roscpp/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/message_filters/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/console_bridge/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/class_loader/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/catkin/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/rospack/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/roslib/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/pluginlib/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/geometry_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/sensor_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/image_transport/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/diagnostic_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/diagnostic_updater/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/self_test/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/camera_calibration_parsers/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/camera_info_manager/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/usb_cam/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/opencv2/package.xml
CMakeFiles/landmarkDetector.dir/src/mcimg.c.o: /opt/ros/groovy/share/cv_bridge/package.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /projects/ros/surfer-main/lab3/landmarkSelfSim/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/landmarkDetector.dir/src/mcimg.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/landmarkDetector.dir/src/mcimg.c.o   -c /projects/ros/surfer-main/lab3/landmarkSelfSim/src/mcimg.c

CMakeFiles/landmarkDetector.dir/src/mcimg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/landmarkDetector.dir/src/mcimg.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /projects/ros/surfer-main/lab3/landmarkSelfSim/src/mcimg.c > CMakeFiles/landmarkDetector.dir/src/mcimg.c.i

CMakeFiles/landmarkDetector.dir/src/mcimg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/landmarkDetector.dir/src/mcimg.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /projects/ros/surfer-main/lab3/landmarkSelfSim/src/mcimg.c -o CMakeFiles/landmarkDetector.dir/src/mcimg.c.s

CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.requires:
.PHONY : CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.requires

CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.provides: CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.requires
	$(MAKE) -f CMakeFiles/landmarkDetector.dir/build.make CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.provides.build
.PHONY : CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.provides

CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.provides.build: CMakeFiles/landmarkDetector.dir/src/mcimg.c.o

CMakeFiles/landmarkDetector.dir/src/findlines.c.o: CMakeFiles/landmarkDetector.dir/flags.make
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: ../src/findlines.c
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: ../manifest.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/cpp_common/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/rostime/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/rosconsole/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/roscpp_traits/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/roscpp_serialization/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/genmsg/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/genpy/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/message_runtime/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/std_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/rosgraph_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/xmlrpcpp/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/roscpp/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/message_filters/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/console_bridge/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/class_loader/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/catkin/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/rospack/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/roslib/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/pluginlib/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/geometry_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/sensor_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/image_transport/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/diagnostic_msgs/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/diagnostic_updater/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/self_test/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/camera_calibration_parsers/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/camera_info_manager/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/usb_cam/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/opencv2/package.xml
CMakeFiles/landmarkDetector.dir/src/findlines.c.o: /opt/ros/groovy/share/cv_bridge/package.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /projects/ros/surfer-main/lab3/landmarkSelfSim/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/landmarkDetector.dir/src/findlines.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/landmarkDetector.dir/src/findlines.c.o   -c /projects/ros/surfer-main/lab3/landmarkSelfSim/src/findlines.c

CMakeFiles/landmarkDetector.dir/src/findlines.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/landmarkDetector.dir/src/findlines.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /projects/ros/surfer-main/lab3/landmarkSelfSim/src/findlines.c > CMakeFiles/landmarkDetector.dir/src/findlines.c.i

CMakeFiles/landmarkDetector.dir/src/findlines.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/landmarkDetector.dir/src/findlines.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /projects/ros/surfer-main/lab3/landmarkSelfSim/src/findlines.c -o CMakeFiles/landmarkDetector.dir/src/findlines.c.s

CMakeFiles/landmarkDetector.dir/src/findlines.c.o.requires:
.PHONY : CMakeFiles/landmarkDetector.dir/src/findlines.c.o.requires

CMakeFiles/landmarkDetector.dir/src/findlines.c.o.provides: CMakeFiles/landmarkDetector.dir/src/findlines.c.o.requires
	$(MAKE) -f CMakeFiles/landmarkDetector.dir/build.make CMakeFiles/landmarkDetector.dir/src/findlines.c.o.provides.build
.PHONY : CMakeFiles/landmarkDetector.dir/src/findlines.c.o.provides

CMakeFiles/landmarkDetector.dir/src/findlines.c.o.provides.build: CMakeFiles/landmarkDetector.dir/src/findlines.c.o

# Object files for target landmarkDetector
landmarkDetector_OBJECTS = \
"CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o" \
"CMakeFiles/landmarkDetector.dir/src/barcode.c.o" \
"CMakeFiles/landmarkDetector.dir/src/digits.c.o" \
"CMakeFiles/landmarkDetector.dir/src/landmark.c.o" \
"CMakeFiles/landmarkDetector.dir/src/mcimg.c.o" \
"CMakeFiles/landmarkDetector.dir/src/findlines.c.o"

# External object files for target landmarkDetector
landmarkDetector_EXTERNAL_OBJECTS =

../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o
../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/src/barcode.c.o
../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/src/digits.c.o
../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/src/landmark.c.o
../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/src/mcimg.c.o
../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/src/findlines.c.o
../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/build.make
../bin/landmarkDetector: CMakeFiles/landmarkDetector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/landmarkDetector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/landmarkDetector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/landmarkDetector.dir/build: ../bin/landmarkDetector
.PHONY : CMakeFiles/landmarkDetector.dir/build

CMakeFiles/landmarkDetector.dir/requires: CMakeFiles/landmarkDetector.dir/src/landmarkDetector.cpp.o.requires
CMakeFiles/landmarkDetector.dir/requires: CMakeFiles/landmarkDetector.dir/src/barcode.c.o.requires
CMakeFiles/landmarkDetector.dir/requires: CMakeFiles/landmarkDetector.dir/src/digits.c.o.requires
CMakeFiles/landmarkDetector.dir/requires: CMakeFiles/landmarkDetector.dir/src/landmark.c.o.requires
CMakeFiles/landmarkDetector.dir/requires: CMakeFiles/landmarkDetector.dir/src/mcimg.c.o.requires
CMakeFiles/landmarkDetector.dir/requires: CMakeFiles/landmarkDetector.dir/src/findlines.c.o.requires
.PHONY : CMakeFiles/landmarkDetector.dir/requires

CMakeFiles/landmarkDetector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/landmarkDetector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/landmarkDetector.dir/clean

CMakeFiles/landmarkDetector.dir/depend:
	cd /projects/ros/surfer-main/lab3/landmarkSelfSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /projects/ros/surfer-main/lab3/landmarkSelfSim /projects/ros/surfer-main/lab3/landmarkSelfSim /projects/ros/surfer-main/lab3/landmarkSelfSim/build /projects/ros/surfer-main/lab3/landmarkSelfSim/build /projects/ros/surfer-main/lab3/landmarkSelfSim/build/CMakeFiles/landmarkDetector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/landmarkDetector.dir/depend

