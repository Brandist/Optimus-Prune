# SLAM

This README's purpose is to explain the architecture of the SLAM process. The explanation of SLAM, how it works, is explained in the general readme file of this project. 

## Slam.cpp 

SLAM is divided into mutliple files indicating different functions or layers of the SLAM process. For example, the Slam.cpp main file takes control over all the different processes of SLAM, this can be seen as the main function. Here we initalise the GPS, IMU, and Lidar data as matrices or structs. These datatypes are the most useful for the mathematical operations for SLAM. The start() function initialises all the processes of the SLAM, these are:

- the map
- EKF
- Odometry (work in progress, this could or should be initialised in the EKF)
- Pathfinding
- Optional: Visual Map

## Map.cpp

The map is responsible for keeping the coordinates up-to-date in a local map, either 3d or 2d. A 2d map can be used, optimally, for path finding. At the moment, the GPS and Lidar data are converted into a custom struct called Nodes, containing the 2d coordinates and the coordinates of their neighbours. These nodes can be used for pathfinding, since they contain the F an G value per node for A star, but at the moment is stored in the map.cpp.

## EKF.cpp

The EKF (Extended Kalman Filter) includes the mathematical operations needed to maintain the position of the robot. Normally, the EKF consists of operations, such as odometry and landmark extraction, that takes in the current matrix containing the state of the robot. Then odometry is performed in order to make the current position more accurate. The map then updates the position. Normally, landmark extraction, with a Lidar, is performed for more accuracy. Landmark extraction is, at the time of writing, not implemented because odometry with GPS-IMU and Lidar data and Lidar-IMU is good stable enough.

The entire documentation on the odometry methods and their uses can be found in the report. Documentation on the EKF can be found here: https://www.iri.upc.edu/people/jsola/JoanSola/objectes/curs_SLAM/SLAM2D/SLAM%20course.pdf

## Astar.cpp

At the time of writing, this file is empty, is hasn't been implemented yet. The current plan is to take in the nodes or matrices as parameters. With the current location, the environment of surrounding the robot, and the end node. The current plan is to find the optimal path, with A Star or Dijkstra (subject to change), from the start to end node while keeping in mind the objects or boundaries in the surrounding environment. 

## VisualMap.cpp

The purpose of this file is to create a 3D map of the surrounding environment concatenated to create the entire map of the field. Within the map, certain points in map are highlighted that can indicate landmarks, odometry features, sick tulips and broccoli, and of course the robot itself.

## Additional information

The entire documentation on SLAM and odometry can be found in the Readme.md in the root of SLAM_API and also in the report of this project.