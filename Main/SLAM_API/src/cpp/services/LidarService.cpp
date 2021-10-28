// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Iservices/ILidarService.h"
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Ihardware/Lidar.h"

using namespace std;

LidarService::LidarService() {

}

bool LidarService::requestData(){
    // Call the hardware layer to get the raw data
    // Do something with raw data to make it something where we can work with
    bool data = lidar.readRawData();
    return false;
}