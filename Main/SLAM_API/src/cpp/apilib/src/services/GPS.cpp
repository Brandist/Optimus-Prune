#include "apilib/Iservices/IGPS.h"

using namespace services;

// TODO:
    // Replace dummy data with real GPS data, this depends on the GPS API from the GPS_API branch
    // Find a way to communicate with the GPS_API output and replace the dummy with said output
GPS::GPS() {
    
}

// requestData should take the output from reading the GPS instead of this dummy data
std::vector<float> GPS::requestData(){
    std::vector<float> gps_data;
    gps_data.push_back(1.0); // x
    gps_data.push_back(2.0); // y
    gps_data.push_back(2.0); // z
    return gps_data;
}

void GPS::setRawData(int raw_data){
    this->raw_data = raw_data;
}

int GPS::getRawData(){
    return this->raw_data;
}