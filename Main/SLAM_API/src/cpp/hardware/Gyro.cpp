// These classes represent the hardware components and receiving their data.
// So readRawData() returns raw Gyro data, the service normalises it and the controller checks for errors
// the SLAM folder can then call these from the controller in order to do math shit with the data

#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Ihardware/Gyro.h"

using namespace std;

Gyro::Gyro(){

}

bool Gyro::readRawData(){
    // request the other API for reading data, send the raw data back to service
    return false;
}