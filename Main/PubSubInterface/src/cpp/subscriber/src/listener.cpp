#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "app_logic_sub/ISomeFolder/ISomeFile.h"
#include "app_logic_sub/ISomeOtherFolder/ISomeOtherFile.h"

// Source code with comments: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29 
void chatterCallBack(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s] ", msg->data.c_str());
}

int main(int argc, char **argv){

    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallBack);

    ros::spin();

    return 0;
}