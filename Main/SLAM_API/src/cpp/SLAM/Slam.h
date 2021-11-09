// SLAM interface
#include <Eigen/Core>
#include <iostream>
#include <string>
#include "../controllers/Icontrollers/IGPSController.h"
#include "../controllers/Icontrollers/IGyroController.h"
#include "../controllers/Icontrollers/ILidarController.h"
#include "mapping/imapping/Imap.h"
#include "EKF/iefk/iefk.h"

#ifndef _slam_h
#define _slam_h

/* TODO:
    - change data types of gps and gyro once known */
namespace SLAM{
    class Slam {
        private:
            controllers::GPSController gps_cont;
            controllers::GyroController gyro_cont;
            controllers::LidarController lidar_cont;
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
            Slam(controllers::GPSController gps_cont, controllers::GyroController gyro_cont, controllers::LidarController lidar_cont);
            Eigen::Vector3f getGPSData();
            int getGyroData();
            Eigen::Matrix3Xf getLidarData();
            void init();
            bool start();
    };
}

#endif