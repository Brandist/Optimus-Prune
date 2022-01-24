#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "subscriber/lidar.h"
#include "subscriber/gps.h"
#include "slam/Slam.h"

using namespace std;

SLAM::Slam slam;

// At the moment, slam.start() is called evertime data is received, so every loop of the ROS communication
// This might be a problem since we basically initialise everything again every loop.
// Can this be a problem in the long run?
void doSomethingWithLidar(const subscriber::lidar::ConstPtr& msg){
    // ROS_INFO("I heard: [%f] ", msg->x[0]); // print some incoming data
    slam.initLidarData(msg->x, msg->y, msg->z);
    slam.start();
}

void doSomethingWithGPS(const subscriber::gps::ConstPtr& msg){
    // ROS_INFO("I heard: [%f] ", msg->x[0]); // print some incoming data
    slam.initGPSData(msg->aX, msg->aY, msg->aZ);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    // initialise the slam object
    slam.init();

    // call the corresponding functions whenever data is received on the corresponding topic
    ros::Subscriber sub_lidar = n.subscribe("lidar_topic", 1000, doSomethingWithLidar);
    ros::Subscriber sub_gps = n.subscribe("gps_topic", 1000, doSomethingWithGPS);

    ros::spin();
    return 0;
}