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
    controllers::GPSController gps_cont;
    controllers::LidarController lidar_cont;

    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    // TODO: add second topic for the GPS, which separate msg
    ros::Publisher gps_data = n.advertise<publisher::gps>("gps_topic", 1000);
    ros::Publisher lidar_data = n.advertise<publisher::lidar>("lidar_topic", 1000);

    ros::Rate loop_rate(10);

    int count=0;
    publisher::gps msg_gps;
    publisher::lidar msg_lidar;
    
    // TODO:
    // change Eigen Matrix to vector vector to reduce complexity
    //  dubbel check if this actually reduces complexity
    while(ros::ok()){
        std::vector<float> g_data = gps_cont.requestData();
        // Eigen::Matrix3Xf l_data = lidar_cont.requestData();
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = lidar_cont.requestPCD();
        std::vector<float> x_a, y_a, z_a;

        // Deprecated code, makes use of the PCD conversion to matrix 
        // std::cout << l_data.cols() << std::endl;
        // for (int i=0; i<l_data.cols(); ++i){
        //     x_a.push_back(l_data.col(i).x());
        //     y_a.push_back(l_data.col(i).y());
        //     z_a.push_back(l_data.col(i).z());
        // }
        for (const auto& point: *cloud){
            x_a.push_back(point.x);
            y_a.push_back(point.y);
            z_a.push_back(point.z);
        }
        msg_lidar.x = x_a;
        msg_lidar.y = y_a;
        msg_lidar.z = z_a;

        msg_gps.aX = g_data.at(0);
        msg_gps.aY = g_data.at(1);
        msg_gps.aZ = g_data.at(2);

        // ROS_INFO("%f ", msg.x[0]);
        lidar_data.publish(msg_lidar);
        gps_data.publish(msg_gps);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}