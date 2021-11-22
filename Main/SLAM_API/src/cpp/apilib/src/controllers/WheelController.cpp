#include "apilib/Icontrollers/IWheelController.h"

using namespace controllers;

WheelController::WheelController(){

}

// Instead of bool, the return value must be something SLAM can work with
/* TODO:
    - change output
    - Add some kind of exception handling
 */
int WheelController::requestData(){
    int data = wheel_service.requestData();
    return data;
}
