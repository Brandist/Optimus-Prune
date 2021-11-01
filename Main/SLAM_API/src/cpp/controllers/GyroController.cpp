#include <iostream>
#include <string>
#include "../Icontrollers/IGyroController.h"
#include "../Iservices/IGyroService.h"

using namespace std;

GyroController::GyroController() {

}

// Instead of bool, the return value must be something SLAM can work with
// Todo:
// - change output
// - Add some kind of exception handling
int GyroController::requestData(){
    int data = gyro_service.requestData();
    return data;
}