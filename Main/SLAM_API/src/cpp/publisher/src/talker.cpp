#include <iostream>
#include "apilib/Icontrollers/IGPSController.h"
#include "apilib/Icontrollers/ILidarController.h"
#include <Eigen/Core>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "publisher/lidar.h"
#include "publisher/gps.h"
#include <Eigen/Core>

using namespace std;

int main(int argc, char **argv) {
    // Instantiate objects
    controllers::GPSController gps_cont;
    controllers::LidarController lidar_cont;

    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    // create the topics for both GPS and Lidar
    ros::Publisher gps_data = n.advertise<publisher::gps>("gps_topic", 1000);
    ros::Publisher lidar_data = n.advertise<publisher::lidar>("lidar_topic", 1000);

    ros::Rate loop_rate(10);

    int count=0;
    // create the gps and lidar message objects
    publisher::gps msg_gps;
    publisher::lidar msg_lidar;
    
    // TODO:
    // change Eigen Matrix to vector vector to reduce complexity
    while(ros::ok()){
        // request gps and lidar data from the apilib library
        std::vector<float> g_data = gps_cont.requestData();
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = lidar_cont.requestPCD();
        std::vector<float> x_a, y_a, z_a;

        // loop through the pointcloud and fill the coordinates
        for (const auto& point: *cloud){
            x_a.push_back(point.x);
            y_a.push_back(point.y);
            z_a.push_back(point.z);
        }

        // fill the message objects
        msg_lidar.x = x_a;
        msg_lidar.y = y_a;
        msg_lidar.z = z_a;

        msg_gps.aX = g_data.at(0);
        msg_gps.aY = g_data.at(1);
        msg_gps.aZ = g_data.at(2);

        // Print message data
        // ROS_INFO("%f ", msg_gps.x[0]);
        // publish the message object to the topic
        lidar_data.publish(msg_lidar);
        gps_data.publish(msg_gps);
        // send it
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}