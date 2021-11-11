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

For localisation, normally SLAM uses the LiDaR on order to extract landmarks for localisation, but since a GPS-RTK is available, we can modify the SLAM to use the GPS for localisation. Ofcourse GPS isnt enough, so landmark extraction and odometry is still necessary for making corrections. Since GPS data is the priority, this repository currently doesnt focus on the landmarks as of 28-10-2021. It does focus on Odometry as of 09-11-2021. Landmarks is being tested

**Parts**

- GPS
- Landmark extraction from mapping
- odometry
- Gyro

### Mapping

- Lidar
- GPS
- landmarks
- coordinates of plants (sick) (?)
- libs for making a map, visualised of just a set of coordinates

### Navigation

- Pathfinding algorithms (D* lite, or A*, something lightweight)
- Formatting of the path data type so we can tell the robot where it needs to go next in a format that the robot understands
  - Whole path?
  - Next node?

## Project structure move to ROS pub-sub based model
- 11-11-2021
  
The entire project works on a ROS pub-sub based model, where the publisher (src/cpp/publisher) sends the GPS/LIDAR each through their different topic. The subscriber (src/cpp/subsriber) then subscribes to those topic and receives the data. The publisher and subscriber both contain only 1 cpp main file. These main files are only responsible to sending and receiving data respectivily. The API and SLAM based logic are done in different packages, both included by their respective pub sub package.

The code of the pub and sub files can be found here: 
- http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

The publisher package includes the apilib packages. apilib contains the controller/services/hardware cpp and header files that communicates with the API of the hardware components. 

The subscriber package includes the slam package. slam contains all the SLAM based logic, which is creating the map, localisation and odometry.

Linking the pub/apilib and sub/slam packages together is achieved by manipulating the CMakeLists.txt an package.xml, both created by the catkin_create_pkg command. (source: https://roboticsbackend.com/ros-include-cpp-header-from-another-package/). The ROS commands used to create the structure are documented and can be found in the resources folder.

**TODO:** 
- Replace the dummy String data to a custom ros-msg containing the GPS and Lidar data

## Additional information

This repository is written in c++ for a ROS-Noetic based implemention: http://wiki.ros.org/noetic
