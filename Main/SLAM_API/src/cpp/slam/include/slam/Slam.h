// SLAM interface
#include <Eigen/Core>
#include <iostream>
#include <vector>
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
            float left_wheel_count;
            float right_wheel_count;
            Eigen::Matrix3Xf lidar_data;
            void setGPSData(Eigen::Vector3f gps_data);
            void setLeftWheelCount(float left_wheel_count);
            void setRightWheelCount(float left_right_count);
            void setLidarData(Eigen::Matrix3Xf lidar_data);
        public:
            Slam();
            Eigen::Vector3f getGPSData();
            float getLeftWheelCount();
            float getRightWheelCount();
            Eigen::Matrix3Xf getLidarData();
            void init();
            void initWheelData(float left_wheel_count, float right_wheel_count);
            void initGPSData(float x, float y, float z);
            void initLidarData(std::vector<float> x, std::vector<float> y, std::vector<float> z);
            bool start();
    };
}

#endif