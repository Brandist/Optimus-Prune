#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "slam/Slam.h"

using namespace std;

void chatterCallBack(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s] ", msg->data.c_str());
}

int main(int argc, char **argv){

    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("gps", 1000, chatterCallBack);

    ros::spin();

    return 0;
}