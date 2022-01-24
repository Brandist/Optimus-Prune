# Optimus-Prune

This Github is divided into branches, each containing functional code for each specific section of this project. The idea is to work in the seperate branches to test the different parts of the robot. Pushing to the main branch should only be done when the code in a branch is fully functional, without faults, works on every branch and contains useful data or code for other branches. It is essential that the code in the main branch should be accessable and runnable by everyone working in the Git, therefore it should be fully documented and commented so that everyone can have a general understanding of what it means and does, and also how to run it.
The branches are as follows:

## ArduMower

Python code for controlling the ArduMower and reading the data from it. 

- Contributor: Ilse

## DATASTORE-LOGGER

cpp code for combining the data from multiple sensors with the configuration of the database and write this data to a database.

- Contributor: Dmitri


## GPS_API

cpp code for reading and manipulating the GPS data. This data needs to be the input for the SLAM.

- Contributor: Brandon

## ROS_STRUCT

A skeleton code in cpp for a basic ROS pub/sub structure with documentation and tutorials explaining each part of a ROS based structure, such as the topics, messages, including libraries and the ROS commands.

- Contributor: Barend

## SLAM_API

SLAM cpp code, realised with the ROS structure from ROS_STRUCT. This code takes the dummy GPS and Lidar data as input (publisher) and the SLAM project subscribes to it. SLAM then perform localisation and mapping techniques on the Lidar data to enhance to robots position, make the map of the surroundings and performs path finding. READMEs are located in the root and in each subdirectory such as the SLAM and external libraries. The code is fully commented with TODO, tips and code explanations.

- Contributor: Barend

## ULTRASONIC_API

cpp code for reading the ultrasonic sensor(s) data. This contains reading and printing the data, custom checks for safety zones and more.

- Contributor: Debora

## Other information:

- The code is written in cpp and python mainly because of the possible ROS implementation for the future. But other languages are acceptable for testing purposes. (JAVA works as wel ROS, although not sure on which versions).
- The Github repository is stationed under Brandons personal account, therefore it might be best to fork the current repository. Or copy the repository (and every branch) and make a new repository.
- Feel free to ask questions of specific parts of the code, you can ask them via mail to the corresponding people. 
