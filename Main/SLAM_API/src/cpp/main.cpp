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
    Slam dummy_slam;

    int gps_data = gps_cont.requestData();
    int gyro_data = gyro_cont.requestData();
    int lidar_data = lidar_cont.requestData();

    // Is there ROS communication here?
    // Maybe send the incoming gps, gyro and lidar data to SLAM via ROS bus
    // then SLAM can read the data, so we dont need to make an instance of SLAM
    // dummy_slam.start();
}