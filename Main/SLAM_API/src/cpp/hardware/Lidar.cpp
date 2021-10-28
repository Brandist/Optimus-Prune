// These classes represent the hardware components and receiving their data.
// So readRawData() returns raw LiDaR data, the service normalises it and the controller checks for errors
// the SLAM folder can then call these from the controller in order to do math shit with the data

#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Ihardware/Lidar.h"

using namespace std;

Lidar::Lidar(){

}

bool Lidar::readRawData(){
    // request the other API for reading data, send the raw data back to service
    return false;
}