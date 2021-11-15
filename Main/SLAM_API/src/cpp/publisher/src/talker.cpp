#include <iostream>
#include "apilib/Icontrollers/IGPSController.h"
#include "apilib/Icontrollers/ILidarController.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "publisher/someMsg.h"
#include <Eigen/Core>

using namespace std;

/* Is there ROS communication here?
 Maybe send the incoming gps, gyro and lidar data to SLAM via ROS bus
 then SLAM can read the data, so we dont need to make an instance of SLAM
 Or make an instance of SLAM and throw the controllers in the constructor so SLAM can directly communicate with the controllers */
int main(int argc, char **argv) {
    controllers::GPSController gps_cont;
    controllers::LidarController lidar_cont;

    int g_data = gps_cont.requestData();
    // Eigen::Matrix3Xf l_data = lidar_cont.requestData();

    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    ros::Publisher gps_data = n.advertise<publisher::someMsg>("gps", 1000);
    ros::Publisher lidar_data = n.advertise<std_msgs::String>("lidar", 1000);

    ros::Rate loop_rate(10);

    int count=0;
    publisher::someMsg msg;
    while(ros::ok()){
        Eigen::Matrix3Xf l_data = lidar_cont.requestData();

        std::vector<double> x_a, y_a, z_a;

        for (int i=0; i<l_data.cols(); ++i){
            x_a.push_back(l_data.col(i).x());
            y_a.push_back(l_data.col(i).y());
            z_a.push_back(l_data.col(i).z());
        }

        msg.x = x_a;
        msg.y = y_a;
        msg.z = z_a;
        
        // print x, y, z first point
        ROS_INFO("%f ", msg.x[0]);
        ROS_INFO("%f ", msg.y[0]);
        ROS_INFO("%f ", msg.z[0]);

        gps_data.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
    // SLAM::Slam slam(gps_cont, gyro_cont, lidar_cont);

    /* Slam should run indefinitely, (untill the robot stops that is)
        Atm, this is 1 iteration, which takes in 1 set of data and makes 1 map (submap of the whole field) */
    // slam.init();
    // slam.start();
}