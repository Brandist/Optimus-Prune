// SLAM interface
#include <Eigen/Core>
#include <iostream>
#include <string>
#include "slam/imapping/Imap.h"
#include "slam/iefk/iefk.h"

#ifndef _slam_h
#define _slam_h

/* TODO:
    - change data types of gps and gyro once known */
namespace SLAM{
    class Slam {
        private:
            map::Map slam_map;
            EKF::Ekf ekf;
            Eigen::Vector3f gps_data;
            int gyro_data;
            Eigen::Matrix3Xf lidar_data;
            void setGPSData(Eigen::Vector3f gps_data);
            void setGyroData(int gyro_data);
            void setLidarData(Eigen::Matrix3Xf lidar_data);
        public:
            Slam();
            Eigen::Vector3f getGPSData();
            int getGyroData();
            Eigen::Matrix3Xf getLidarData();
            void init();
            bool start();
    };
}

#endif