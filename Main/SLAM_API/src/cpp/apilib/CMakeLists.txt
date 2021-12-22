cmake_minimum_required(VERSION 3.0.2)
project(apilib)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

find_package(PCL 1.10 REQUIRED)

# set(PCL_INCLUDE_DIRS /usr/include/pcl-1.10/)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ${PROJECT_NAME}
 CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/controllers/GPSController.cpp
  src/controllers/LidarController.cpp
  src/services/GPS.cpp
  src/services/Lidar.cpp
)

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${PCL_LIBRARIES})
# ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES}
install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)