// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include "Iservices/IGPSService.h"
#include "../hardware/Ihardware/GPS.h"

using namespace services;

GPSService::GPSService() {
    
}

/*  The conversion from raw data to SLAM-readable data
    input: Dont know yet
    output: 3d Vector */
int GPSService::convertRawDataToPosVector(){
    int data = getRawData();
    // Do the actual conversion here
    return raw_data;
}

int GPSService::requestData(){
    // Call the hardware layer to get the raw data
    int data = gps.readRawData();
    int gps_data = convertRawDataToPosVector();
    return gps_data;
}

void GPSService::setRawData(int raw_data){
    this->raw_data = raw_data;
}

int GPSService::getRawData(){
    return this->raw_data;
}