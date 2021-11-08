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

    slam_map.init();

    // Work in progress
    // get the odometry data, landmark extraction etc
    // update the map accordingly
    // call the pathfinding algorithm

    return false;
}

/* TODO:
     - is it needed to make classes (entities) of the components containing the incoming data and calculations, or do we do that in the map class?
     - GPS   
     - Gyro
     - Lidar */     

// So far: A reasoning for these methods are not yet found
bool Slam::doSomethingWithGPSData(){
    int data = getGPSData();
    std::cout << data << std::endl;
    return false;
}

bool Slam::doSomethingWithGyroData(){
    int data = getGyroData();
    std::cout << data << std::endl;
    return false;
}

bool Slam::doSomethingWithLidarData(){
    Eigen::Matrix3Xf data = getLidarData();
    std::cout << data << std::endl;
    return false;
}

// Setting the data should not be necessary
void Slam::setGPSData(int gps_data){
    this->gps_data = gps_data;
}

int Slam::getGPSData(){
    return this->gps_data;
}

// Setting the data should not be necessary
void Slam::setGyroData(int gyro_data){
    this->gyro_data = gyro_data;
}

int Slam::getGyroData(){
    return this->gps_data;
}

// Setting the data should not be necessary
void Slam::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Slam::getLidarData(){
    return this->lidar_data;
}