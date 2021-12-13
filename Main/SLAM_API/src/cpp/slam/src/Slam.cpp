#include "slam/Slam.h"

/* The main SLAM loop
    the map initalisation containing the lidar, gps and IMU data
        - the map will be an object that is used for pathfinding
        - the map contains points (vectors) containing the lidar data
            - each type of vector has a label indicating if its a wall, possible path, begin and end point (optional)
        - TODO: Implement the SLAM math functions (odometry, landmarks) output and make it visual in the map 
    The slam process should include the following:
        - map building and updating
        - Odometry
            - lidar, IMU
        - the output should be included in the map building as well */
using namespace SLAM;

Slam::Slam(){}

void Slam::init(){
    this->slam_map = map::Map();
    this->ekf = EKF::Ekf();
}

void Slam::initGPSData(float x, float y, float z){
    setGPSData(Eigen::Vector3f(x,y,z));
}

void Slam::initLidarData(std::vector<float> x, std::vector<float> y, std::vector<float> z){
    int matrix_size = x.size();
    Eigen::Matrix3Xf mat(3, matrix_size);

    for (int i=0; i<matrix_size; i++){
        float temp_x = x.at(i);
        float temp_y = y.at(i);
        float temp_z = z.at(i);
        Eigen::Vector3f vec(temp_x, temp_y, temp_z);
        mat.col(i) = vec;
    }

    setLidarData(mat);
}

bool Slam::start(){
    // This should be a method just like the Lidar data
    slam_map.setGPSData(getGPSData());
    slam_map.setLidarData(getLidarData());

    slam_map.init();
    ekf.init(slam_map.getRobotPositionVector(), slam_map.getLidarData());
    // constructor of a_star
    // slam_map.printMap();

    ekf.performOdometry();
    slam_map.updateRobotPosition(ekf.getRobotPosition());

    // slam_map.printMap();

    // ekf.performLandmarkExtraction();
    // slam_map.updateRobotPosition(ekf.getRobotPosition());

    // Work in progress
    // get lidar and IMU to process the odometry data etc
    // update the map accordingly
    // call the pathfinding algorithm

    // a_star init which will request the set of Nodes (containing all the nodes)
    // a_start calculateOptimalPath will take in the robot_pos and end_node

    // some exception checking here, return false if something went wrong
    return false;
}

// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------
void Slam::setGPSData(Eigen::Vector3f gps_data){
    this->gps_data = gps_data;
}

Eigen::Vector3f Slam::getGPSData(){
    return this->gps_data;
}

void Slam::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Slam::getLidarData(){
    return this->lidar_data;
}