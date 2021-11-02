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

For localisation, normally SLAM uses the LiDaR on order to extract landmarks for localisation, but since a GPS-RTK is available, we can modify the SLAM to use the GPS for localisation. Ofcourse GPS isnt enough, so landmark extraction and odometry is still necessary for making corrections. Since GPS data is the priority, this repository currently doesnt focus on the landmarks and odometry as of 28-10-2021

**Parts**

- GPS
- Landmark extraction from mapping
- odometry
- Gyro

### Mapping

- Lidar
- GPS
- landmarks
- coordinates of plants (sick)
- libs for making a map, visualised of just a set of coordinates

### Navigation

- Pathfinding algorithms (D* lite, or A*, something lightweight)
- Formatting of the path data type so we can tell the robot where it needs to go next in a format that the robot understands
  - Whole path?
  - Next node?

## Additional information

This repository is written in c++ for a ROS-Noetic based implemention: http://wiki.ros.org/noetic
