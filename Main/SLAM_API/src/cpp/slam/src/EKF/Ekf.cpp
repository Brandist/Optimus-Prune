#include "slam/iefk/iefk.h"

using namespace EKF;

Ekf::Ekf(){

}

void Ekf::init(Eigen::Vector3f robot_position, Eigen::Matrix3Xf lidar_data){
    this->robot_position = robot_position;
    this->lidar_data = lidar_data;
}

// TODO:
// Perform odometry from multiple sensors
// maybe odometry requires other files, for structure, not sure yet
void Ekf::performOdometry(){
    Eigen::Vector3f curr_robot_pos = getRobotPosition();
    Eigen::Matrix3Xf mat = getLidarData();


    // std::cout << mat.size() << std::endl;
    // after all calculations 
    setRobotPosition(curr_robot_pos);
}

// Is this needed?
// Maybe GPS & odo is good enough?
void Ekf::performLandmarkExtraction(){

    // after all calculations
    Eigen::Vector3f new_robot_position = this->robot_position;
    setRobotPosition(new_robot_position);
}

// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------
void Ekf::setRobotPosition(Eigen::Vector3f robot_position){
    this->robot_position = robot_position;
}

Eigen::Vector3f Ekf::getRobotPosition(){
    return this->robot_position;
}

void Ekf::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Ekf::getLidarData(){
    return this->lidar_data;
}