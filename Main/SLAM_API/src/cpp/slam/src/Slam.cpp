#include "slam/Slam.h"

/* This is the main SLAM file. Consider this as the main loop
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
    // setGPSData(gps_cont.requestData());
    /* dummy vector data for robot position since I cannot simulate the raw gps data yet */
    setGPSData(Eigen::Vector3f(0.0, 2.0, 1.0));
    // setGyroData(gyro_cont.requestData());
    // setLidarData(lidar_cont.requestData());

    this->slam_map = map::Map(getLidarData(), getGPSData());
    this->ekf = EKF::Ekf();
}

bool Slam::start(){
    slam_map.init();
    ekf.init();
    // constructor of a_star
    slam_map.printMap();

    ekf.performOdometry();
    slam_map.updateRobotPosition(ekf.getRobotPosition());

    ekf.performLandmarkExtraction();
    slam_map.updateRobotPosition(ekf.getRobotPosition());


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

void Slam::setGyroData(int gyro_data){
    this->gyro_data = gyro_data;
}

int Slam::getGyroData(){
    return this->gyro_data;
}

void Slam::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Slam::getLidarData(){
    return this->lidar_data;
}