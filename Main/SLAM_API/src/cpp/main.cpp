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

    int gps_data = gps_cont.requestData();
    int lidar_data = lidar_cont.requestData();

    Slam dummy_slam(gps_data, lidar_data);
}