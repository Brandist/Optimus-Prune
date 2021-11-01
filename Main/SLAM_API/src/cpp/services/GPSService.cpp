// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include "../Iservices/IGPSService.h"
#include "../Ihardware/GPS.h"

using namespace std;

GPSService::GPSService() {
    
}

// Not sure yet what type of data this will be, GPS data for SLAM must likely will be a 3d Vector, ask Brandon
int GPSService::convertRawDataToVectors(int raw_data){
    return raw_data;
}

int GPSService::requestData(){
    // Call the hardware layer to get the raw data
    // Do something with raw data to make it something where we can work with
    int data = gps.readRawData();
    int gps_data = convertRawDataToVectors(data);
    return gps_data;
}