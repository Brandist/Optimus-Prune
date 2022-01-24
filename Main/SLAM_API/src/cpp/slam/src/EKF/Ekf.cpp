#include "slam/iefk/iefk.h"

using namespace EKF;

/* The EKF is responsible for keeping the data up-to-date and performing localisation enhancing methods
 such as odometry, in order to update the robots position
 An EKF status matrix is used to store the robots coordinates and status, as wel as the coordinates of certain
 objects or features for odometry. 
 More information on the mathematical side of the EKF can be found on the report and also here:
 https://www.iri.upc.edu/people/jsola/JoanSola/objectes/curs_SLAM/SLAM2D/SLAM%20course.pdf 
*/
Ekf::Ekf(){

}

void Ekf::init(Eigen::Vector3f robot_position, Eigen::Matrix3Xf lidar_data){
    this->robot_position = robot_position;
    this->lidar_data = lidar_data;
}


// TODO:
// Perform odometry from multiple sensors, maybe make seperate function per sensor (GPS, Lidar, IMU etc)
// Think about of odometry requires a seperate class or function.
// How to add a new file and compile it can be found in the README in the root of the project
void Ekf::performOdometry(){
    Eigen::Vector3f curr_robot_pos = getRobotPosition();
    Eigen::Matrix3Xf mat = getLidarData();

    // after all calculations 
    setRobotPosition(curr_robot_pos);
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