#include <iostream>
#include <string>
#include "../Icontrollers/IGPSController.h"
#include "../Iservices/IGPSService.h"

using namespace std;

GPSController::GPSController(){

}

// Instead of bool, the return value must be something SLAM can work with
bool GPSController::requestData(){
    bool validation = gps_service.requestData();
    
    // Do something here with validation, what to do when something goes wrong
    return validation;
}
