#include <iostream>
#include <string>
#include <Eigen/Core>
#include "slam.h"
#include "../Icontrollers/IGPSController.h"
#include "../Icontrollers/IGyroController.h"
#include "../Icontrollers/ILidarController.h"

using namespace std;

Slam::Slam(GPSController gps_cont, GyroController gyro_cont, LidarController lidar_cont){
    this->gps_cont = gps_cont;
    this->gyro_cont = gyro_cont;
    this->lidar_cont = lidar_cont;
}

bool Slam::start(){
    setLidarData(lidar_cont.requestData());

    bool gps_result = doSomethingWithGPSData();
    bool lidar_result = doSomethingWithLidarData();
    bool gyro_result = doSomethingWithGyroData();
    return false;
}

// TODO:
// - make classes for the 3 components, each with their needed methods and calculations:
//     - GPS   
//     - Gyro
//     - Lidar
bool Slam::doSomethingWithGPSData(){
    int data = getGPSData();
    cout << data << endl;
    return false;
}

bool Slam::doSomethingWithGyroData(){
    int data = getGyroData();
    cout << data << endl;
    return false;
}

bool Slam::doSomethingWithLidarData(){
    Eigen::Matrix3Xf data = getLidarData();
    cout << data << endl;
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