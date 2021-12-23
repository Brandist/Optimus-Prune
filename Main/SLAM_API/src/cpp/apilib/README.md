# APILIB

apilib is a library containing the communication between the GPS and Lidar. The goal is to include this library in the publisher program. The publisher then can call the requestdata method that requests the raw GPS and Lidar data from the hardware and returns readable data in the form of custom structs, vectors, matrices and pointcloud objects from the PCL library. 

## Controllers 

The GPS Controller is exceptionhandling and returning any errors that may occur when calling the GPS requestdata. The same goes for the Lidar.

## Service/hardware layer

The GPS and Lidar files are responsible for setting up a connection to the hardware the request the data. For example, the GPS should return the $x, y, z$ coordinates globally, also the IMU data. The Lidar should return an pointcloud object from the PCL library. At the moment, the connection to the hardware isn't realised. Instead, dummy data is written for the GPS and the Lidar data is filled with PCD Poinclouds. The PCD files contain real poincloud data from field tests in the brocolli field (06-12-2021).

## Additional data

This directory is a library, meaning that it cannot run on its own, it needs to be included in order to test and run the methods. The publisher directory includes this library, calls these methods and sends the data on the ROS bus.