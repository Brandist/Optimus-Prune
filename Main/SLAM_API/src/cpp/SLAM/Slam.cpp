#include <iostream>
#include <string>
#include <Eigen/Core>
#include "Slam.h"
#include "mapping/imapping/Imap.h"
#include "../controllers/Icontrollers/IGPSController.h"
#include "../controllers/Icontrollers/IGyroController.h"
#include "../controllers/Icontrollers/ILidarController.h"

/* This is the main SLAM file. Consider this as the main loop
    initalise SLAM with the controllers for the different components
    then the SLAM process can start
    The start process is still work in progress
    the map initalisation containing the lidar, gps and IMU data
        - the map will be an object that is used for pathfinding
        - the map contains points (vectors) containing the lidar data
            - each type of vector has a label indicating if its a wall, possible path, begin and end point
        - TODO: - Create the map, either via an map object, or set of vector, something that is easy to visualise
                - Implement the SLAM math functions (odometry, landmarks) output and make it visual in the map 
    The slam process should include (apart from map building) the following:
        - Odometry
        - Landmark extraction from the lidar data
        - the output should be included in the map building as well */
using namespace SLAM;

Slam::Slam(){
    start();
}

Slam::Slam(controllers::GPSController gps_cont, controllers::GyroController gyro_cont, controllers::LidarController lidar_cont){
    this->gps_cont = gps_cont;
    this->gyro_cont = gyro_cont;
    this->lidar_cont = lidar_cont;

    start();
}

bool Slam::start(){
    setGPSData(gps_cont.requestData());
    setGyroData(gyro_cont.requestData());
    setLidarData(lidar_cont.requestData());

    map::Map slam_map(getLidarData(), getGPSData());
    // constructor of a_star
    slam_map.init();

    // Work in progress
    // get and process the odometry data, landmark extraction etc
    //  - odometry and landmark extraction should be called EKF
    //  - unknown if EKF should have direct communication with the map
    // get the GPS, Gyro, IMU data 
    //  - process the data
    // update the map accordingly
    // call the pathfinding algorithm

    // a_star init which will request the set of Nodes (containing all the nodes)
    // a_start calculateOptimalPath will take in the robot_pos and end_nodes 

    return false;
}


// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------
void Slam::setGPSData(int gps_data){
    this->gps_data = gps_data;
}

int Slam::getGPSData(){
    return this->gps_data;
}

void Slam::setGyroData(int gyro_data){
    this->gyro_data = gyro_data;
}

int Slam::getGyroData(){
    return this->gps_data;
}

void Slam::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Slam::getLidarData(){
    return this->lidar_data;
}