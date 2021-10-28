# SLAM based information and other stuff

## SLAM parts

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



### Navigation


## Additional information

This repository is written in c++ for a ROS-Noetic based implemention: http://wiki.ros.org/noetic
