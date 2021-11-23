#include "slam/iefk/iefk.h"

using namespace EKF;

Ekf::Ekf(){
    this->slam_map = map::Map();
}

void Ekf::init(Eigen::Vector3f robot_position, float left_wheel_count, float right_wheel_count){
    this->robot_position = robot_position;
    this->left_wheel_count = left_wheel_count;
    this->right_wheel_count = right_wheel_count;
}

// Find a way where the wheel data is coming from and how to get it 
// (Is it IMU or something else?)
void Ekf::performOdometry(){
    Eigen::Vector3f cur_robot_pos = getRobotPosition();
    float left_wheel_count = getLeftWheelCount();
    float right_wheel_count = getRightWheelCount();

    // Do calculations with IMU as well?

    // after all calculations
    updateRobotPosition();
}

// Is this needed?
// Maybe GPS & odo is good enough?
// If needed, this method requests the Lidar data in order to extract unique landmarks
// With the coordinates of these landmarks and the current robot_pos, we can take another guess of the robot_pos
void Ekf::performLandmarkExtraction(){

    // after all calculations
    updateRobotPosition();
}

// update robots position locally and in the map
void Ekf::updateRobotPosition(){
    Eigen::Vector3f new_robot_position = this->robot_position;
    setRobotPosition(new_robot_position);
}

// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------

void Ekf::setLeftWheelCount(float left_wheel_count){
    this->left_wheel_count = left_wheel_count;
}

void Ekf::setRightWheelCount(float right_wheel_count){
    this->right_wheel_count = right_wheel_count;
}

float Ekf::getLeftWheelCount(){
    return this->left_wheel_count;
}

float Ekf::getRightWheelCount(){
    return this->right_wheel_count;
}

void Ekf::setRobotPosition(Eigen::Vector3f robot_position){
    this->robot_position = robot_position;
}

Eigen::Vector3f Ekf::getRobotPosition(){
    return this->robot_position;
}