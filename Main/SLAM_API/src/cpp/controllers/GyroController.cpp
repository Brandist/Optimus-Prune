#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Icontrollers/IGyroController.h"
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Iservices/IGyroService.h"

using namespace std;

GyroController::GyroController() {

}

// Instead of bool, the return value must be something SLAM can work with
bool GyroController::requestData(){
    bool validation = gyro_service.requestData();
    // Do something here with validation, what to do when something goes wrong
    return validation;
}