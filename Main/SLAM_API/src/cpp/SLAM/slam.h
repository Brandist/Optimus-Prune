// SLAM interface
#include <Eigen/Core>
#include "../controllers/Icontrollers/IGPSController.h"
#include "../controllers/Icontrollers/IGyroController.h"
#include "../controllers/Icontrollers/ILidarController.h"

#ifndef _slam_h
#define _slam_h

/* TODO:
    - change data types of gps and gyro
    - think about whats private and public, maybe even protected
*/
namespace SLAM{
    class Slam {
        private:
            controllers::GPSController gps_cont;
            controllers::GyroController gyro_cont;
            controllers::LidarController lidar_cont;
            int gps_data;
            int gyro_data;
            Eigen::Matrix3Xf lidar_data;
            void setGPSData(int gps_data);
            void setGyroData(int gyro_data);
            void setLidarData(Eigen::Matrix3Xf lidar_data);
            bool start();
        public:
            Slam();
            Slam(controllers::GPSController gps_cont, controllers::GyroController gyro_cont, controllers::LidarController lidar_cont);
            bool doSomethingWithGPSData();
            bool doSomethingWithLidarData();
            bool doSomethingWithGyroData();
            int getGPSData();
            int getGyroData();
            Eigen::Matrix3Xf getLidarData();
    };
}

#endif