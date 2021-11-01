// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include "../Iservices/IGyroService.h"
#include "../Ihardware/Gyro.h"

using namespace std;

GyroService::GyroService() {

}

int GyroService::requestData(){
    // Call the hardware layer to get the raw data
    // Do something with raw data to make it something where we can work with
    int data = gyro.readRawData();
    return false;
}