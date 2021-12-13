#include "apilib/Icontrollers/IGPSController.h"

using namespace controllers;

GPSController::GPSController(){

}

// TODO:
    // - Add some kind of exception handling
std::vector<float> GPSController::requestData(){
    std::vector<float> data = gps_service.requestData();
    return data;
}
