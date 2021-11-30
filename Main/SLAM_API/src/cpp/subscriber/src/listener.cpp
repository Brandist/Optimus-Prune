#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "subscriber/lidar.h"
#include "subscriber/gps.h"
#include "slam/Slam.h"

using namespace std;

SLAM::Slam slam;

void doSomethingWithLidar(const subscriber::lidar::ConstPtr& msg){
    // ROS_INFO("I heard: [%f] ", msg->x[0]);
    slam.initLidarData(msg->x, msg->y, msg->z);
    slam.start();
}

void doSomethingWithGPS(const subscriber::gps::ConstPtr& msg){
    // ROS_INFO("I heard: [%f] ", msg->x[0]);
    slam.initGPSData(msg->aX, msg->aY, msg->aZ);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    slam.init();

    ros::Subscriber sub_lidar = n.subscribe("lidar_topic", 1000, doSomethingWithLidar);
    ros::Subscriber sub_gps = n.subscribe("gps_topic", 1000, doSomethingWithGPS);

    ros::spin();
    return 0;
}