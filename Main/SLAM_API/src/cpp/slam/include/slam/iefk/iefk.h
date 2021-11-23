#include <iostream>
#include <string>
#include <Eigen/Core>
#include "slam/imapping/Imap.h"

#ifndef _ekf_h
#define _ekf_h

namespace EKF{
    class Ekf {
        private:
            map::Map slam_map;
            Eigen::Vector3f robot_position;
            float left_wheel_count;
            float right_wheel_count;
            void setRobotPosition(Eigen::Vector3f robot_position);
            void setLeftWheelCount(float left_wheel_count);
            void setRightWheelCount(float left_right_count);
        public:
            Ekf();
            void init(Eigen::Vector3f robot_position, float left_wheel_count, float right_wheel_count);
            void performOdometry();
            void performLandmarkExtraction();
            void updateRobotPosition();
            Eigen::Vector3f getRobotPosition();
            float getLeftWheelCount();
            float getRightWheelCount();
    };
}

#endif