#include <iostream>
#include <string>
#include <Eigen/Core>
#include <math.h>
#include "slam/imapping/Imap.h"

#ifndef _ekf_h
#define _ekf_h

namespace EKF{
    class Ekf {
        private:
            map::Map slam_map;
            Eigen::Vector3f robot_position;
            float left_wheel_tick;
            float right_wheel_tick;
            void setRobotPosition(Eigen::Vector3f robot_position);
            void setLeftWheelTick(float left_wheel_tick);
            void setRightWheelTick(float right_wheel_tick);
        public:
            Ekf();
            void init(Eigen::Vector3f robot_position, float left_wheel_tick, float right_wheel_tick);
            void performOdometry();
            void performLandmarkExtraction();
            Eigen::Vector3f getRobotPosition();
            float getLeftWheelTick();
            float getRightWheelTick();
    };
}

#endif