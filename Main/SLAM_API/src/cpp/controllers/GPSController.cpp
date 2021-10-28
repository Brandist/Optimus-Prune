#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Icontrollers/IGPSController.h"
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Iservices/IGPSService.h"

using namespace std;

GPSController::GPSController(){

}

// Instead of bool, the return value must be something SLAM can work with
bool GPSController::requestData(){
    bool validation = gps_service.requestData();
    // Do something here with validation, what to do when something goes wrong
    return validation;
}
