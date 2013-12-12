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
CMAKE_SOURCE_DIR = /home/refnode/projects/Ref

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/refnode/projects/Ref/build

# Utility rule file for ROSBUILD_genmsg_py.

# Include the progress variables for this target.
include CMakeFiles/ROSBUILD_genmsg_py.dir/progress.make

CMakeFiles/ROSBUILD_genmsg_py: ../src/Ref/msg/__init__.py

../src/Ref/msg/__init__.py: ../src/Ref/msg/_BotStatus.py
../src/Ref/msg/__init__.py: ../src/Ref/msg/_BotToRef.py
../src/Ref/msg/__init__.py: ../src/Ref/msg/_HoverBot.py
../src/Ref/msg/__init__.py: ../src/Ref/msg/_image.py
../src/Ref/msg/__init__.py: ../src/Ref/msg/_Position.py
../src/Ref/msg/__init__.py: ../src/Ref/msg/_controls.py
../src/Ref/msg/__init__.py: ../src/Ref/msg/_CurrentStatus.py
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/__init__.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --initpy /home/refnode/projects/Ref/msg/BotStatus.msg /home/refnode/projects/Ref/msg/BotToRef.msg /home/refnode/projects/Ref/msg/HoverBot.msg /home/refnode/projects/Ref/msg/image.msg /home/refnode/projects/Ref/msg/Position.msg /home/refnode/projects/Ref/msg/controls.msg /home/refnode/projects/Ref/msg/CurrentStatus.msg

../src/Ref/msg/_BotStatus.py: ../msg/BotStatus.msg
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/roslib/cmake/../../../lib/roslib/gendeps
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/std_msgs/msg/Header.msg
../src/Ref/msg/_BotStatus.py: ../msg/Position.msg
../src/Ref/msg/_BotStatus.py: ../manifest.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/cpp_common/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/rostime/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/roscpp_traits/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/roscpp_serialization/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/genmsg/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/genpy/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/message_runtime/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/rosconsole/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/std_msgs/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/rosgraph_msgs/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/xmlrpcpp/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/roscpp/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/catkin/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/rospack/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/roslib/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/rosgraph/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/rospy/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/geometry_msgs/package.xml
../src/Ref/msg/_BotStatus.py: /home/refnode/projects/april/april_msgs/manifest.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/message_filters/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/sensor_msgs/package.xml
../src/Ref/msg/_BotStatus.py: /opt/ros/groovy/share/tf/package.xml
../src/Ref/msg/_BotStatus.py: /home/refnode/projects/hoverTracker/manifest.xml
../src/Ref/msg/_BotStatus.py: /home/refnode/projects/april/april_msgs/msg_gen/generated
../src/Ref/msg/_BotStatus.py: /home/refnode/projects/hoverTracker/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/_BotStatus.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --noinitpy /home/refnode/projects/Ref/msg/BotStatus.msg

../src/Ref/msg/_BotToRef.py: ../msg/BotToRef.msg
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/roslib/cmake/../../../lib/roslib/gendeps
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/std_msgs/msg/Header.msg
../src/Ref/msg/_BotToRef.py: ../manifest.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/cpp_common/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/rostime/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/roscpp_traits/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/roscpp_serialization/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/genmsg/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/genpy/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/message_runtime/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/rosconsole/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/std_msgs/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/rosgraph_msgs/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/xmlrpcpp/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/roscpp/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/catkin/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/rospack/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/roslib/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/rosgraph/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/rospy/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/geometry_msgs/package.xml
../src/Ref/msg/_BotToRef.py: /home/refnode/projects/april/april_msgs/manifest.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/message_filters/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/sensor_msgs/package.xml
../src/Ref/msg/_BotToRef.py: /opt/ros/groovy/share/tf/package.xml
../src/Ref/msg/_BotToRef.py: /home/refnode/projects/hoverTracker/manifest.xml
../src/Ref/msg/_BotToRef.py: /home/refnode/projects/april/april_msgs/msg_gen/generated
../src/Ref/msg/_BotToRef.py: /home/refnode/projects/hoverTracker/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/_BotToRef.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --noinitpy /home/refnode/projects/Ref/msg/BotToRef.msg

../src/Ref/msg/_HoverBot.py: ../msg/HoverBot.msg
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/roslib/cmake/../../../lib/roslib/gendeps
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/std_msgs/msg/Header.msg
../src/Ref/msg/_HoverBot.py: ../manifest.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/cpp_common/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/rostime/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/roscpp_traits/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/roscpp_serialization/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/genmsg/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/genpy/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/message_runtime/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/rosconsole/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/std_msgs/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/rosgraph_msgs/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/xmlrpcpp/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/roscpp/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/catkin/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/rospack/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/roslib/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/rosgraph/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/rospy/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/geometry_msgs/package.xml
../src/Ref/msg/_HoverBot.py: /home/refnode/projects/april/april_msgs/manifest.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/message_filters/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/sensor_msgs/package.xml
../src/Ref/msg/_HoverBot.py: /opt/ros/groovy/share/tf/package.xml
../src/Ref/msg/_HoverBot.py: /home/refnode/projects/hoverTracker/manifest.xml
../src/Ref/msg/_HoverBot.py: /home/refnode/projects/april/april_msgs/msg_gen/generated
../src/Ref/msg/_HoverBot.py: /home/refnode/projects/hoverTracker/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/_HoverBot.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --noinitpy /home/refnode/projects/Ref/msg/HoverBot.msg

../src/Ref/msg/_image.py: ../msg/image.msg
../src/Ref/msg/_image.py: /opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py
../src/Ref/msg/_image.py: /opt/ros/groovy/share/roslib/cmake/../../../lib/roslib/gendeps
../src/Ref/msg/_image.py: /opt/ros/groovy/share/std_msgs/msg/Header.msg
../src/Ref/msg/_image.py: ../msg/Position.msg
../src/Ref/msg/_image.py: ../manifest.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/cpp_common/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/rostime/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/roscpp_traits/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/roscpp_serialization/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/genmsg/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/genpy/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/message_runtime/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/rosconsole/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/std_msgs/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/rosgraph_msgs/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/xmlrpcpp/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/roscpp/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/catkin/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/rospack/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/roslib/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/rosgraph/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/rospy/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/geometry_msgs/package.xml
../src/Ref/msg/_image.py: /home/refnode/projects/april/april_msgs/manifest.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/message_filters/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/sensor_msgs/package.xml
../src/Ref/msg/_image.py: /opt/ros/groovy/share/tf/package.xml
../src/Ref/msg/_image.py: /home/refnode/projects/hoverTracker/manifest.xml
../src/Ref/msg/_image.py: /home/refnode/projects/april/april_msgs/msg_gen/generated
../src/Ref/msg/_image.py: /home/refnode/projects/hoverTracker/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/_image.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --noinitpy /home/refnode/projects/Ref/msg/image.msg

../src/Ref/msg/_Position.py: ../msg/Position.msg
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/roslib/cmake/../../../lib/roslib/gendeps
../src/Ref/msg/_Position.py: ../manifest.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/cpp_common/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/rostime/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/roscpp_traits/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/roscpp_serialization/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/genmsg/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/genpy/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/message_runtime/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/rosconsole/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/std_msgs/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/rosgraph_msgs/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/xmlrpcpp/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/roscpp/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/catkin/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/rospack/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/roslib/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/rosgraph/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/rospy/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/geometry_msgs/package.xml
../src/Ref/msg/_Position.py: /home/refnode/projects/april/april_msgs/manifest.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/message_filters/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/sensor_msgs/package.xml
../src/Ref/msg/_Position.py: /opt/ros/groovy/share/tf/package.xml
../src/Ref/msg/_Position.py: /home/refnode/projects/hoverTracker/manifest.xml
../src/Ref/msg/_Position.py: /home/refnode/projects/april/april_msgs/msg_gen/generated
../src/Ref/msg/_Position.py: /home/refnode/projects/hoverTracker/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/_Position.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --noinitpy /home/refnode/projects/Ref/msg/Position.msg

../src/Ref/msg/_controls.py: ../msg/controls.msg
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/roslib/cmake/../../../lib/roslib/gendeps
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/std_msgs/msg/Header.msg
../src/Ref/msg/_controls.py: ../manifest.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/cpp_common/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/rostime/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/roscpp_traits/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/roscpp_serialization/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/genmsg/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/genpy/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/message_runtime/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/rosconsole/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/std_msgs/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/rosgraph_msgs/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/xmlrpcpp/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/roscpp/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/catkin/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/rospack/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/roslib/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/rosgraph/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/rospy/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/geometry_msgs/package.xml
../src/Ref/msg/_controls.py: /home/refnode/projects/april/april_msgs/manifest.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/message_filters/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/sensor_msgs/package.xml
../src/Ref/msg/_controls.py: /opt/ros/groovy/share/tf/package.xml
../src/Ref/msg/_controls.py: /home/refnode/projects/hoverTracker/manifest.xml
../src/Ref/msg/_controls.py: /home/refnode/projects/april/april_msgs/msg_gen/generated
../src/Ref/msg/_controls.py: /home/refnode/projects/hoverTracker/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/_controls.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --noinitpy /home/refnode/projects/Ref/msg/controls.msg

../src/Ref/msg/_CurrentStatus.py: ../msg/CurrentStatus.msg
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/roslib/cmake/../../../lib/roslib/gendeps
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/std_msgs/msg/Header.msg
../src/Ref/msg/_CurrentStatus.py: ../msg/Position.msg
../src/Ref/msg/_CurrentStatus.py: ../manifest.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/cpp_common/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/rostime/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/roscpp_traits/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/roscpp_serialization/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/genmsg/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/genpy/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/message_runtime/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/rosconsole/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/std_msgs/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/rosgraph_msgs/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/xmlrpcpp/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/roscpp/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/catkin/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/rospack/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/roslib/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/rosgraph/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/rospy/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/geometry_msgs/package.xml
../src/Ref/msg/_CurrentStatus.py: /home/refnode/projects/april/april_msgs/manifest.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/message_filters/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/sensor_msgs/package.xml
../src/Ref/msg/_CurrentStatus.py: /opt/ros/groovy/share/tf/package.xml
../src/Ref/msg/_CurrentStatus.py: /home/refnode/projects/hoverTracker/manifest.xml
../src/Ref/msg/_CurrentStatus.py: /home/refnode/projects/april/april_msgs/msg_gen/generated
../src/Ref/msg/_CurrentStatus.py: /home/refnode/projects/hoverTracker/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/refnode/projects/Ref/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/Ref/msg/_CurrentStatus.py"
	/opt/ros/groovy/share/rospy/rosbuild/scripts/genmsg_py.py --noinitpy /home/refnode/projects/Ref/msg/CurrentStatus.msg

ROSBUILD_genmsg_py: CMakeFiles/ROSBUILD_genmsg_py
ROSBUILD_genmsg_py: ../src/Ref/msg/__init__.py
ROSBUILD_genmsg_py: ../src/Ref/msg/_BotStatus.py
ROSBUILD_genmsg_py: ../src/Ref/msg/_BotToRef.py
ROSBUILD_genmsg_py: ../src/Ref/msg/_HoverBot.py
ROSBUILD_genmsg_py: ../src/Ref/msg/_image.py
ROSBUILD_genmsg_py: ../src/Ref/msg/_Position.py
ROSBUILD_genmsg_py: ../src/Ref/msg/_controls.py
ROSBUILD_genmsg_py: ../src/Ref/msg/_CurrentStatus.py
ROSBUILD_genmsg_py: CMakeFiles/ROSBUILD_genmsg_py.dir/build.make
.PHONY : ROSBUILD_genmsg_py

# Rule to build all files generated by this target.
CMakeFiles/ROSBUILD_genmsg_py.dir/build: ROSBUILD_genmsg_py
.PHONY : CMakeFiles/ROSBUILD_genmsg_py.dir/build

CMakeFiles/ROSBUILD_genmsg_py.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ROSBUILD_genmsg_py.dir/clean

CMakeFiles/ROSBUILD_genmsg_py.dir/depend:
	cd /home/refnode/projects/Ref/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/refnode/projects/Ref /home/refnode/projects/Ref /home/refnode/projects/Ref/build /home/refnode/projects/Ref/build /home/refnode/projects/Ref/build/CMakeFiles/ROSBUILD_genmsg_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ROSBUILD_genmsg_py.dir/depend

