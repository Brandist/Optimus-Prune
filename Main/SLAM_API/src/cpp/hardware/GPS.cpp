// These classes represent the hardware components and receiving their data.
// So readRawData() returns raw GPS data, the service normalises it and the controller checks for errors
// the SLAM folder can then call these from the controller in order to do math shit with the data

#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Ihardware/GPS.h"

using namespace std;

GPS::GPS(){

}

int GPS::readRawData(){
    // request the other API for reading data, send the raw data back to service
    int gps_data = getData();
    return gps_data;
}

// This should be the raw data from the GPS
void GPS::setData(int data){
    this->data = data;
}

// This should be the raw data from the GPS
int GPS::getData(){
    return this->data;
}