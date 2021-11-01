#include <iostream>

#include "Icontrollers/IGPSController.h"
#include "Icontrollers/IGyroController.h"
#include "Icontrollers/ILidarController.h"
#include "SLAM/slam.h"

using namespace std;

int main() {
    GPSController gps_cont;
    GyroController gyro_cont;
    LidarController lidar_cont;
    Slam dummy_slam(gps_cont, gyro_cont, lidar_cont);

    // Is there ROS communication here?
    // Maybe send the incoming gps, gyro and lidar data to SLAM via ROS bus
    // then SLAM can read the data, so we dont need to make an instance of SLAM
    // Or make an instance of SLAM and throw the controllers in the constructor so SLAM can directly communicate with the controllers
    dummy_slam.start();
}