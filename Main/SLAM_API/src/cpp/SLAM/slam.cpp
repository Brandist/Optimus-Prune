#include <iostream>
#include <string>
#include "slam.h"

using namespace std;

Slam::Slam(int gps_data, int lidar_data){
    this->gps_data = gps_data;
    this->lidar_data = lidar_data;
}

bool Slam::doSomethingWithGPSData(){
    int data = getGPSData();
    return false;
}

bool Slam::doSomethingWithLidarData(){
    int data = getLidarData();
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
void Slam::setLidarData(int lidar_data){
    this->lidar_data = lidar_data;
}

int Slam::getLidarData(){
    return this->lidar_data;
}