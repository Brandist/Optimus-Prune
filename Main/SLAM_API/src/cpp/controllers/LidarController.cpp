#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Icontrollers/ILidarController.h"
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Iservices/ILidarService.h"

using namespace std;

LidarController::LidarController() {

}

// Instead of bool, the return value must be something SLAM can work with
bool LidarController::requestData(){
    bool validation = lidar_service.requestData();
    // Do something here with validation, what to do when something goes wrong
    return validation;
}
