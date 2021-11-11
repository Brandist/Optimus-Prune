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
            void setRobotPosition(Eigen::Vector3f robot_position);
        public:
            Ekf();
            void init();
            void performOdometry();
            void performLandmarkExtraction();
            void updateRobotPosition();
            Eigen::Vector3f getRobotPosition();
    };
}

#endif