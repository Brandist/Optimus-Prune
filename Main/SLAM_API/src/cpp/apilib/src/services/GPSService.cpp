#include "apilib/Iservices/IGPSService.h"

using namespace services;

GPSService::GPSService() {
    
}

// This should actually be the readGps msg and the entire message should be a struct (made by Brandon) and filled there
std::vector<float> GPSService::requestData(){
    // Call the hardware layer to get the raw data
    int data = gps.readRawData();

    std::vector<float> gps_data;
    gps_data.push_back(0.0); // x
    gps_data.push_back(2.0); // y
    gps_data.push_back(100.0); // z
    return gps_data;
}

void GPSService::setRawData(int raw_data){
    this->raw_data = raw_data;
}

int GPSService::getRawData(){
    return this->raw_data;
}