// SLAM interface
#include <Eigen/Core>
#include "../Icontrollers/IGPSController.h"
#include "../Icontrollers/IGyroController.h"
#include "../Icontrollers/ILidarController.h"

#ifndef _slam_h
#define _slam_h

class Slam {
    private:
        GPSController gps_cont;
        GyroController gyro_cont;
        LidarController lidar_cont;
        int gps_data;
        int gyro_data;
        Eigen::Matrix3Xf lidar_data;
    public:
        Slam(GPSController gps_cont, GyroController gyro_cont, LidarController lidar_cont);
        bool start();
        bool doSomethingWithGPSData();
        bool doSomethingWithLidarData();
        bool doSomethingWithGyroData();
        void setGPSData(int gps_data);
        int getGPSData();
        void setLidarData(Eigen::Matrix3Xf lidar_data);
        Eigen::Matrix3Xf getLidarData();
        void setGyroData(int gyro_data);
        int getGyroData();
};

#endif