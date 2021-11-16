#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "subscriber/lidar.h"
#include "slam/Slam.h"

using namespace std;

SLAM::Slam slam;

void chatterCallBack(const subscriber::lidar::ConstPtr& msg){
    // ROS_INFO("I heard: [%f] ", msg->x[0]);
    slam.initLidarData(msg->x, msg->y, msg->z);
    slam.start();
}

int main(int argc, char **argv){
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    slam.init();

    ros::Subscriber sub = n.subscribe("lidar_topic", 1000, chatterCallBack);

    ros::spin();

    return 0;
}