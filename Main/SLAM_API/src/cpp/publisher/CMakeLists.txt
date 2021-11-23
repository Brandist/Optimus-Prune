cmake_minimum_required(VERSION 3.0.2)
project(publisher)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  apilib
)

add_message_files(
  FILES
  lidar.msg
  gps.msg
  wheel.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
 CATKIN_DEPENDS roscpp std_msgs message_runtime apilib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
# add_dependencies(talker talker_cpp)