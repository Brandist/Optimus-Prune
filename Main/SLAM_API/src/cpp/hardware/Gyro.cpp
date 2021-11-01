// These classes represent the hardware components and receiving their data.
// So readRawData() returns raw Gyro data, the service normalises it and the controller checks for errors
// the SLAM folder can then call these from the controller in order to do math shit with the data

#include <iostream>
#include <string>
#include "../Ihardware/Gyro.h"

using namespace std;

Gyro::Gyro(){

}

int Gyro::readRawData(){
    // request the other API for reading data, send the raw data back to service
    int data = getData();
    return data;
}

// This should be the raw data from the GPS
// Setting the raw data should not be necessary
void Gyro::setData(int data){
    this->data = data;
}

// This should be the raw data from the GPS
int Gyro::getData(){
    return this->data;
}