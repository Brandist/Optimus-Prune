#include "apilib/Icontrollers/IGPSController.h"

using namespace controllers;

GPSController::GPSController(){

}

// TODO:
    // - Add exception handling
std::vector<float> GPSController::requestData(){
    std::vector<float> data = gps.requestData();
    return data;
}
