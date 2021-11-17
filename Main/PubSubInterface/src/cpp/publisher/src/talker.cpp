#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "publisher/someMsg.h"
#include "app_logic_pub/ISomeFolder/ISomeFile.h"
#include "app_logic_pub/ISomeOtherFolder/ISomeOtherFile.h"

// Source code with comments: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29 
int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    // ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Publisher some_msg_data = n.advertise<publisher::someMsg>("some_topic", 1000);
    ros::Rate loop_rate(10);

    int count=0;

    publisher::someMsg msg;
    while(ros::ok()){
        msg.some_variable = 10;
        msg.some_variable_2 = 11;
        ROS_INFO("%d ", msg.some_variable);
        ROS_INFO("%d ", msg.some_variable_2);

        some_msg_data.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}