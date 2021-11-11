// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include "Iservices/IGyroService.h"
#include "../hardware/Ihardware/Gyro.h"

using namespace services;

GyroService::GyroService() {

}

/*  The conversion from raw data to SLAM-readable data
    input: Dont know yet
    output: Dont know yet */
int GyroService::convertRawDatatoSomeData(){
    int data = getRawData();
    // Do the actual conversion here
    return raw_data;
}

int GyroService::requestData(){
    // Call the hardware layer to get the raw data
    // Do something with raw data to make it something where we can work with
    int data = gyro.readRawData();
    int gyro_data = convertRawDatatoSomeData();
    return false;
}

void GyroService::setRawData(int raw_data){
    this->raw_data = raw_data;
}

int GyroService::getRawData(){
    return this->raw_data;
}