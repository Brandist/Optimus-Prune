# SLAM based information and other stuff

## The communication between SLAM and hardware

The communication between the SLAM process and hardware is written in an API format. So SLAM can request the formatted data by calling the API. The API the requests the raw_data from the hardware components by calling the respective API's of the components (GPS, Gyro, Lidar). The API is divided in 3 layers:

- Controllers
- Services
- Hardware

Where the controller layer calls the service and service calls the hardware. The controller layer gets the converted data, which SLAM can work with, from the service and is also responsible for exceptionhandling. The service layer gets the raw_data from the hardware components and converts the raw_data to formatted data, sends it back to the controller. The hardware layer is responsible for requesting the raw_data from the components API's. 

Having the API separated into 3 parts makes it easier to read, easier to understand and every layer is responsible for different structures within the API. So if something goes wrong with the hardware external API communication, we know that the fault is in the hardware layer. The same counts for the service layer. If we get the raw_data, and something goes wrong in the conversion, the controller layer notices it and says that there is a error coming from the service layer.

Direct communication between SLAM and these controllers is still something we're looking at. This can be done via ROS by separating the SLAM API and the SLAM process, or direct reading in the same project. 
## SLAM parts

- reading data from the controllers
- Localisation
- Mapping
- Navigation

### Localisation 

For localisation, normally SLAM uses the LiDaR on order to extract landmarks for localisation, but since a GPS-RTK is available, we can modify the SLAM to use the GPS for localisation. GPS might not be enough, so odometry and landmark extraction might be necessary for making corrections, this requires testing with real field data. Although, the SLAM structure is made with odometry and landmark extraction in mind, GPS localisation is the priority.

**Parts**

- GPS
- Lidar odometry/landmark extraction
- odometry with IMU (accelometer and gyrometer)

### Mapping

Internally, mapping is done via a set of coordinates in the form of a vector, essentially making a matrix containing the x, y, z coordinates of every point. The points can be points from the pointcloud, thanks to the Lidar, and the GPS point indicating the robot position. For visual mapping, the map created from the raw Lidar data, because pointclouds can be easily viewed in software, it is still unclear how the concatenation of multiple pointclouds works. 

- Lidar
- GPS
- landmarks
- libs for making a map, visualised of just a set of coordinates

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

Linking the pub/apilib and sub/slam packages together is achieved by manipulating the CMakeLists.txt an package.xml, both created by the catkin_create_pkg command. (source: https://roboticsbackend.com/ros-include-cpp-header-from-another-package/). The ROS commands used to create the structure are documented and can be found in the resources folder.

## Additional information

This repository is written in c++ for a ROS-Noetic based implemention: http://wiki.ros.org/noetic
