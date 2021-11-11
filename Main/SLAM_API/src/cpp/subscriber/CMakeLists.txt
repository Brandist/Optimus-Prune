cmake_minimum_required(VERSION 3.0.2)
project(subscriber)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  slam
)

catkin_package(
 CATKIN_DEPENDS roscpp std_msgs slam
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
# add_dependencies(talker beginner_tutorials_generate_messages_cpp)