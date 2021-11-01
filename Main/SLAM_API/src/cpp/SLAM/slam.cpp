#include <iostream>
#include <string>
#include "slam.h"

using namespace std;

Slam::Slam(){
}

bool Slam::start(){
    bool gps_result = doSomethingWithGPSData();
    bool lidar_result = doSomethingWithLidarData();
    bool gyro_result = doSomethingWithGyroData();
    return false;
}

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
    int data = getLidarData();
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
void Slam::setLidarData(int lidar_data){
    this->lidar_data = lidar_data;
}

int Slam::getLidarData(){
    return this->lidar_data;
}