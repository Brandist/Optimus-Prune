# SLAM based information and other stuff

SLAM stands for Simultaneous Localization and Mapping. SLAM is defined as the problem of constructing or updating a map of an unknown environment while simultaneously keeping track of the localistion of the robot in the environment. There have been several algorithms available for solving it, such as particle filter, EKF (Extended Kalman Filter), GraphSLAM, and more. In this project, the localisation part of SLAM will be done mainly with a GPS-RTK, and a localisation method called odometry. The mapping part will be done with a Lidar. The Lidar (Light Detection and Ranging of Laser Imaging Detection and Ranging), The output of a lidar is a point cloud, a set of 3D points ($x, y, z$). Which indicates coordinates and the intensity of points of the environment, where a map can be made around the robot. The robot can use this map to extract features to makeits position more robust. 

This is the general definition and process of SLAM. Within the SLAM map, the robot can find its way by just driving or use a pathfinding algorithm to find the optimal path to its destination. 

## Why SLAM?

SLAM is responsible for a lot of processes in the localisation and mapping of the environment. For example, without SLAM, the robot does not know where it is in relation to the environment. This can become a problem when the robot executes processes where the localisation is of utmost importance, such as cutting branches of a tree, or avoiding objects/humans/animals while driving. These are examples of why localisation is important in the project. In some projects, localisation can be done with a GPS alone, but SLAM provides a robust way to fuse multiple sensors to make localisation more robust and accurate. These sensors can be a lidar, IMU or other sensors that provide data which can be useful for localisation. 

Mapping is also essential, since with creating a map of the surrounding, the robot can localise itself within said map. This helps with keeping track of the position of the robot in relation to the environment. The map can also be used to detect object and places of interest around the robot by implement object detection or feature extraction methods on the environment data. These points can be placed on the map, in order save the position of the these points for future runs. 

Having a visualised map of the whole field, either a pointcloud or an image of the whole field, can be useful for the farmers as well. And the pointcloud can be used in the future, and can be used to further enhance localisation and mapping since the whole field is already known, given that it is up-to-date. 

Although it might not be required, the map can also be used to implement pathfinding. This can be useful for making the driving process optimal by giving the robot coordinates, or nodes, that the robot needs to traverse. The pathfinding algorithm does not have to be complex, since it is known that the fields where the robot is going to operate in are divided into rows, which are straight lines. This means that most likely the optimal path will be a straight line from A to B with not much deviation. But pathfinding can still be implemented to make the whole system more secure and robust.

## Are there any alternatives?

SLAM is not a method or a function perse, it is more of a set of operations fused together in order to maintain localisation and mapping. This means that an alternative to the whole SLAM operation is not the correct way to look at it. SLAM can be implemented in multiple ways, with mutliple and different sensors. For example, Visual SLAM (VSLAM), uses multiple visualised sensors such as cameras, lidars, ultrasonic sensors, in order to capture frames and extract points from these frames to track where the robot is. The lidar is used to create a map of the surroundings. Lidar SLAM is a way that only uses the Lidar as input data, also to localise itself. It does this with a method called landmark extraction, which extracts unique points of the environment that can be followed while driving to calculate the distance between the robot and the landmark. Other SLAM methods, such as GraphSLAM, which is a 2D way to construct a map, i.e. a gridmap. GraphSLAM can be used to construct a path from A to B by using a pathfinding algorithm. This is used in the videogame industry. 

## The communication between SLAM and hardware

The communication between the SLAM process and hardware is written as an API. Where the publisher requests data from the corresponding hardware controller. The controller handles the exceptions and requests the data from the hardware. The hardware class itself has direct communication with the hardware component. The hardware layer, called services, is also responsible for possible formatting of the incoming data. Most of the time this will be done by the other API, these are developed by other people in this project. With this structure way we can pinpoint the errors that are made. For example, if an error occured which has something to do with the hardware, the fault must lie in the hardware layer and all the exceptions are caught in the controller layer. The structure is as follows:

- apilib/src/controllers/GPSController.cpp
- apilib/src/controllers/LidarController.cpp
- apilib/src/service/GPS.cpp
- apilib/src/service/Lidar.cpp

With there corresponding header files in the include directory.

Having the API separated into 3 parts makes it easier to read, easier to understand and every layer is responsible for different structures within the API. So if something goes wrong with the hardware external API communication, we know that the fault is in the hardware layer. The same counts for the service layer. If we get the raw_data, and something goes wrong in the conversion, the controller layer notices it and says that there is a error coming from the service layer.

The data, GPS and lidar, are each converted to their own ROS messages in the publisher directory. The talker.cpp is responsible for calling the implementing the apilib and calling the controllers. Writing the output to ROS specific messages containing GPS and Lidar data. These messages are then published, each on their own ROS topics. This way the subscriber node, which is SLAM, can subscribe to the given topics and convert the ROS messages back
## SLAM parts

- Reading data from the controllers
- Localisation
- Mapping
- Navigation

### Localisation 

For localisation, normally SLAM uses the LiDaR on order to extract landmarks for localisation, but since a GPS-RTK is available, we can modify the SLAM to use the GPS for localisation. GPS might not be enough, so odometry and landmark extraction might be necessary for making corrections, this requires testing with real field data. Although, the SLAM structure is made with odometry and landmark extraction in mind, GPS localisation is the priority.

**Parts**

- GPS
- Lidar odometry
- Odometry with IMU (accelometer and gyrometer)

### Mapping

Internally, mapping is done via a set of coordinates in the form of a vector, essentially making a matrix containing the $x, y, z$ coordinates of every point. The points can be points from the pointcloud, thanks to the Lidar, and the GPS point indicating the robot position. For visual mapping, the map created from the raw Lidar data, because pointclouds can be easily viewed in software, it is still unclear how the concatenation of multiple pointclouds works. 

- Lidar
- GPS
- Landmarks
- libs for making a map, visualised or a set of coordinates

### Navigation

Navigation is essentially a pathfinding algorithm used for calculating the optimal path from point A to B. Where A is the current robot position, indicated by the GPS and corrected by odometry and possibly landmark extraction, and B is the current end-node, which will be the end of the row or as far as the Lidar can see. If Point A is the end of the row, then point B will be the start coordinates of the next row, so the optimal path will be a turn to the next row.

- Pathfinding algorithms (D* lite, or A*, something lightweight)
- Formatting of the path data type so we can tell the robot where it needs to go next in a format that the robot understands
  - Whole path?
  - Next node?

## Project structure move to ROS pub-sub based model

- **When completed:** 11-11-2021

The entire project works on a ROS pub-sub based model, where the publisher (src/cpp/publisher) sends the GPS/LIDAR each through their different topic. The subscriber (src/cpp/subsriber) then subscribes to those topic and receives the data. The publisher and subscriber both contain only 1 cpp main file. These main files are only responsible to sending and receiving data respectivily. The API and SLAM based logic are done in different packages, both included by their respective pub sub package.

The code of the pub and sub files can be found here: 
- http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

The publisher package includes the apilib packages. apilib contains the controller/services/hardware cpp and header files that communicates with the API of the hardware components. 

The subscriber package includes the slam package. slam contains all the SLAM based logic, which is creating the map, localisation and odometry.

Linking the pub/apilib and sub/slam packages together is achieved by manipulating the CMakeLists.txt and package.xml, both created by the catkin_create_pkg command. (source: https://roboticsbackend.com/ros-include-cpp-header-from-another-package/). The ROS commands used to create the structure are documented and can be found in the resources folder.

## Additional information

- This repository is written in C++ for a [ROS-Noetic](http://wiki.ros.org/noetic) based implemention on Ubuntu version 18. 
- After performing all the requirements and includes in order to build this project. It can be run with the commands stated in [resources/ros_notes.md](https://github.com/Brandist/Optimus-Prune/blob/SLAM_API/Main/SLAM_API/resources/ros_notes.md)