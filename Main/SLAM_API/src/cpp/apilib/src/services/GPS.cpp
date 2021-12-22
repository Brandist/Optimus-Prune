#include "apilib/Iservices/IGPS.h"

using namespace services;

GPS::GPS() {
    
}

// This should actually be the readGps msg and the entire message
std::vector<float> GPS::requestData(){
    std::vector<float> gps_data;
    gps_data.push_back(1.0); // x
    gps_data.push_back(2.0); // y
    gps_data.push_back(2.0); // z which is a grid-based map.
    return gps_data;
}

void GPS::setRawData(int raw_data){
    this->raw_data = raw_data;
}

int GPS::getRawData(){
    return this->raw_data;
}