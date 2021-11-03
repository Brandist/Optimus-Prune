#include <iostream>

#include "controllers/Icontrollers/IGPSController.h"
#include "controllers/Icontrollers/IGyroController.h"
#include "controllers/Icontrollers/ILidarController.h"
#include "SLAM/slam.h"

using namespace std;

int main() {
    controllers::GPSController gps_cont;
    controllers::GyroController gyro_cont;
    controllers::LidarController lidar_cont;
    SLAM::Slam dummy_slam(gps_cont, gyro_cont, lidar_cont);

    // Is there ROS communication here?
    // Maybe send the incoming gps, gyro and lidar data to SLAM via ROS bus
    // then SLAM can read the data, so we dont need to make an instance of SLAM
    // Or make an instance of SLAM and throw the controllers in the constructor so SLAM can directly communicate with the controllers
}