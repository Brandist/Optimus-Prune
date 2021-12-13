#include "slam/Slam.h"

/* The main SLAM loop
    initalise SLAM with the controllers for the different components
    then the SLAM process can start
    The start process is still work in progress
    the map initalisation containing the lidar, gps and IMU data
        - the map will be an object that is used for pathfinding
        - the map contains points (vectors) containing the lidar data
            - each type of vector has a label indicating if its a wall, possible path, begin and end point
        - TODO: Implement the SLAM math functions (odometry, landmarks) output and make it visual in the map 
    The slam process should include the following:
        - map building and updating
        - Odometry
        - Landmark extraction from the lidar data
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
    // Some error handling for security, this should be done with exception handling later on
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

// TODO: Think about what methods should be called once and what continously
bool Slam::start(){
    // This should be a method just like the Lidar data
    slam_map.setGPSData(getGPSData());
    slam_map.setLidarData(getLidarData());

    slam_map.init();
    ekf.init(slam_map.getRobotPositionVector());
    // constructor of a_star
    // slam_map.printMap();

    ekf.performOdometry();
    slam_map.updateRobotPosition(ekf.getRobotPosition());

    // slam_map.printMap();

    // ekf.performLandmarkExtraction();
    // slam_map.updateRobotPosition(ekf.getRobotPosition());

    // Work in progress
    // get and process the odometry data, landmark extraction etc
    //  - odometry and landmark extraction should be called EKF
    // get the GPS, Gyro, IMU data 
    //  - process the data
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