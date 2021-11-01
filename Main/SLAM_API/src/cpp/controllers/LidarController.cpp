#include <iostream>
#include <string>
#include "../Icontrollers/ILidarController.h"
#include "../Iservices/ILidarService.h"

using namespace std;

LidarController::LidarController() {

}

// Instead of bool, the return value must be something SLAM can work with
int LidarController::requestData(){
    int validation = lidar_service.requestData();
    // Do something here with validation, what to do when something goes wrong
    return validation;
}
