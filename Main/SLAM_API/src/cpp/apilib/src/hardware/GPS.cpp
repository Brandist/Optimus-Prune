#include "apilib/Ihardware/GPS.h"

using namespace hardware;

// These files are meant to communicate with the other API's (direct hardware access)
GPS::GPS(){

}

int GPS::readRawData(){
    // request the other API for reading data, send the raw data back to service
    setData(10);
    int data = getData();
    return data;
}

void GPS::setData(int data){
    this->data = data;
}

int GPS::getData(){
    return this->data;
}