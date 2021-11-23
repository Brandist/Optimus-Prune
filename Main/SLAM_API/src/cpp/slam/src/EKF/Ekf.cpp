#include "slam/iefk/iefk.h"

using namespace EKF;

float tick_old_l = 4;
float tick_old_r = 6;
static float dis_between_wheels = 0.80;
// radius of the wheel, subject to change
static float radius_wheel = 0.40;
static float tick_per_revo = 1;

Ekf::Ekf(){
    this->slam_map = map::Map();
}

void Ekf::init(Eigen::Vector3f robot_position, float left_wheel_tick, float right_wheel_tick){
    this->robot_position = robot_position;
    this->left_wheel_tick = left_wheel_tick;
    this->right_wheel_tick = right_wheel_tick;
}

// Find a way where the wheel data is coming from and how to get it 
// (Is it IMU or something else?)
void Ekf::performOdometry(){
    Eigen::Vector3f curr_robot_pos = getRobotPosition();
    float tick_l = getLeftWheelTick();
    float tick_r = getRightWheelTick();

    // std::cout << tick_l << std::endl;
    // std::cout << tick_r << std::endl;

    // calculate difference between left and right wheel ticks counted by the encoders
    float tick_delta_l = tick_l - tick_old_l;
    tick_old_l = tick_l;
    float tick_delta_r = tick_r - tick_old_r;
    tick_old_r = tick_r;

    // std::cout << tick_old_l << std::endl;
    // std::cout << tick_old_r << std::endl;

    // std::cout << tick_delta_l << std::endl;
    // std::cout << tick_delta_r << std::endl;

    // calculate distance traveled by the left and right wheel  
    float dis_delta_l = 2 * M_PI * radius_wheel * (tick_delta_l / tick_per_revo);
    float dis_delta_r = 2 * M_PI * radius_wheel * (tick_delta_r / tick_per_revo);

    // std::cout << dis_delta_l << std::endl;
    // std::cout << dis_delta_r << std::endl;

    float dis_c = abs((dis_delta_l + dis_delta_r)) / 2;

    float theta = (dis_delta_r - dis_delta_l) / dis_between_wheels;

    float x_new = curr_robot_pos.x() + dis_c * cos(theta);
    float y_new = curr_robot_pos.y() + dis_c * sin(theta);

    std::cout << "x: " << x_new << std::endl;
    std::cout << "y: " << y_new << std::endl << std::endl;

    // after all calculations 
    setRobotPosition(Eigen::Vector3f{x_new, y_new, curr_robot_pos.z()});
}

// Is this needed?
// Maybe GPS & odo is good enough?
// If needed, this method requests the Lidar data in order to extract unique landmarks
// With the coordinates of these landmarks and the current robot_pos, we can take another guess of the robot_pos
void Ekf::performLandmarkExtraction(){

    // after all calculations
    Eigen::Vector3f new_robot_position = this->robot_position;
    setRobotPosition(new_robot_position);
}

// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------

void Ekf::setLeftWheelTick(float left_wheel_tick){
    this->left_wheel_tick = left_wheel_tick;
}

void Ekf::setRightWheelTick(float right_wheel_tick){
    this->right_wheel_tick = right_wheel_tick;
}

float Ekf::getLeftWheelTick(){
    return this->left_wheel_tick;
}

float Ekf::getRightWheelTick(){
    return this->right_wheel_tick;
}

void Ekf::setRobotPosition(Eigen::Vector3f robot_position){
    this->robot_position = robot_position;
}

Eigen::Vector3f Ekf::getRobotPosition(){
    return this->robot_position;
}