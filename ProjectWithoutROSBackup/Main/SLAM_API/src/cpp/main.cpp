#include <iostream>

#include "controllers/Icontrollers/IGPSController.h"
#include "controllers/Icontrollers/IGyroController.h"
#include "controllers/Icontrollers/ILidarController.h"
#include "SLAM/Slam.h"

using namespace std;

/* Is there ROS communication here?
 Maybe send the incoming gps, gyro and lidar data to SLAM via ROS bus
 then SLAM can read the data, so we dont need to make an instance of SLAM
 Or make an instance of SLAM and throw the controllers in the constructor so SLAM can directly communicate with the controllers */
int main() {
    controllers::GPSController gps_cont;
    controllers::GyroController gyro_cont;
    controllers::LidarController lidar_cont;
    SLAM::Slam slam(gps_cont, gyro_cont, lidar_cont);

    /* Slam should run indefinitely, (untill the robot stops that is)
        Atm, this is 1 iteration, which takes in 1 set of data and makes 1 map (submap of the whole field) */
    slam.init();
    slam.start();
}