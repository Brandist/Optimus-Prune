#include "apilib/Icontrollers/IGPSController.h"

using namespace controllers;

GPSController::GPSController(){

}

// TODO:
    // Add exception handling
    // Change the output variable from vector to something that contains all GPS data
    //      - which is currently unknown (maybe look at the GPS ROS message in the msg directory of publisher)
std::vector<float> GPSController::requestData(){
    std::vector<float> data = gps.requestData();
    return data;
}
