#include <iostream>
#include <string>
#include "../Icontrollers/IGPSController.h"
#include "../Iservices/IGPSService.h"

using namespace controllers;

GPSController::GPSController(){

}

// Instead of bool, the return value must be something SLAM can work with
/* TODO:
    - change output
    - Add some kind of exception handling
 */
int GPSController::requestData(){
    int data = gps_service.requestData();
    return data;
}