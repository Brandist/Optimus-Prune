#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "app_logic_pub/ISomeFolder/ISomeFile.h"
#include "app_logic_pub/ISomeOtherFolder/ISomeOtherFile.h"

// Source code with comments: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29 
int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);

    int count=0;

    while(ros::ok()){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello peeps " << count;
        msg.data = ss.str();

        ROS_INFO("%s ", msg.data.c_str());

        chatter_pub.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}