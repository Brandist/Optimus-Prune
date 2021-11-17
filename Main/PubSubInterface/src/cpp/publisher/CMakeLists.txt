cmake_minimum_required(VERSION 3.0.2)
project(publisher)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  app_logic_pub
)

add_message_files(
  FILES
  someMsg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
 CATKIN_DEPENDS roscpp std_msgs message_runtime app_logic_pub
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})