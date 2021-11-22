#include "apilib/Iservices/IWheelService.h"

using namespace services;

WheelService::WheelService() {
    
}

// This should actually be the readGps msg and the entire message should be a struct (made by Brandon) and filled there
int WheelService::requestData(){
    // Call the hardware layer to get the raw data
    int data = wheel.readRawData();
    return data;
}

void WheelService::setRawData(int raw_data){
    this->raw_data = raw_data;
}

int WheelService::getRawData(){
    return this->raw_data;
}