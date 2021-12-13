#include "apilib/Ihardware/Lidar.h"

using namespace hardware;

// These files are meant to communicate with the other API's (direct hardware access)
Lidar::Lidar(){

}

int Lidar::readRawData(){
    // request the other API for reading data, send the raw data back to service
    // The PCL code should be either in the service or in the Lidar API. 
    setData(10);
    int data = getData();
    return data;
}

void Lidar::setData(int data){
    this->data = data;
}

int Lidar::getData(){
    return this->data;
}