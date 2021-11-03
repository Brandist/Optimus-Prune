#include <iostream>
#include <string>
#include "Icontrollers/IGyroController.h"
#include "../services/Iservices/IGyroService.h"
using namespace controllers;

GyroController::GyroController() {

}

// Instead of bool, the return value must be something SLAM can work with
/* TODO:
    - change output
    - Add some kind of exception handling
 */
int GyroController::requestData(){
    int data = gyro_service.requestData();
    return data;
}