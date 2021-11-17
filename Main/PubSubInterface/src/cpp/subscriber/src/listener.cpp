#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "subscriber/someMsg.h"
#include "app_logic_sub/ISomeFolder/ISomeFile.h"
#include "app_logic_sub/ISomeOtherFolder/ISomeOtherFile.h"

// Source code with comments: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29 
void chatterCallBack(const subscriber::someMsg::ConstPtr& msg){
    ROS_INFO("I heard: [%d] ", msg->some_variable);
    ROS_INFO("I heard: [%d] ", msg->some_variable_2);
}

int main(int argc, char **argv){

    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("some_topic", 1000, chatterCallBack);

    ros::spin();

    return 0;
}