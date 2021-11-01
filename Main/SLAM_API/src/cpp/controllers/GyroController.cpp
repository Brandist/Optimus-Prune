#include <iostream>
#include <string>
#include "../Icontrollers/IGyroController.h"
#include "../Iservices/IGyroService.h"

using namespace std;

GyroController::GyroController() {

}

// Instead of bool, the return value must be something SLAM can work with
int GyroController::requestData(){
    int validation = gyro_service.requestData();
    // Do something here with validation, what to do when something goes wrong
    return validation;
}