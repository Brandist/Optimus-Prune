// These classes represent the hardware components and receiving their data.
// So readRawData() returns raw LiDaR data, the service normalises it and the controller checks for errors
// the SLAM folder can then call these from the controller in order to do math shit with the data

#include <iostream>
#include <string>
#include "../Ihardware/Lidar.h"

using namespace std;

Lidar::Lidar(){

}

int Lidar::readRawData(){
    // request the other API for reading data, send the raw data back to service
    setData(10);
    int data = getData();
    return data;
}

// This should be the raw data from the GPS
// Setting the raw data should not be necessary
void Lidar::setData(int data){
    this->data = data;
}

// This should be the raw data from the GPS
int Lidar::getData(){
    return this->data;
}