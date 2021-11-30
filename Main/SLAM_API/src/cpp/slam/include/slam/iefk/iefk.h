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
            void setRobotPosition(Eigen::Vector3f robot_position);
        public:
            Ekf();
            void init(Eigen::Vector3f robot_position);
            void performOdometry();
            void performLandmarkExtraction();
            Eigen::Vector3f getRobotPosition();
    };
}

#endif