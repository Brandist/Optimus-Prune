# ROS working steps:

ROS Noetic should already be installed thanks to Ijdo

## Important

Make sure to run 

> roscore

in a different terminal, and keep it running

## ROS installation and sourcing: 

ROS is installed under:
> /opt/ros/noetic/

The include files are located here as well

Source:
> source /opt/ros/noetic/setup.bash

OR for zsh
> source /opt/ros/noetic/setup.zsh

You can add this to your /.bashrc or /zshrc to avoid sourcing everytime a new terminal is opened

## Create a package: http://wiki.ros.org/ROS/Tutorials/CreatingPackage

Root of your project make a package

> catkin_create_pkg somePackageName std_msgs roscpp

Where std_msgs and roscpp are the dependencies needed. These packages can be includes in the packages.xml etc .. This will create a directory and CMakeLists, package.xml etc containing everything that is needed for catkin

In the root of your project, compike with:
> catkin_make 

This will generate the build and devel directories

To generate the package files
> source ./devel/setup.zsh

This will add your ROS package to the ROS package list, which can be seen in:
> rosrun ? 

## Running a ros package

In the root of the directory. Where the build and devel directories are present.

> catkin_make

Dont forget to source the setup.zsh or setup.bash

## Tip:

Make a Makefile containing the catkin_make and clean etc