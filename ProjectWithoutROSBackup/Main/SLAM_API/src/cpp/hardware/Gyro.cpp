#include <iostream>
#include <string>
#include "Ihardware/Gyro.h"

using namespace hardware;

Gyro::Gyro(){

}

/* TODO: 
 - change data type to raw lidar data type
 - remove set method
*/
int Gyro::readRawData(){
    // request the other API for reading data, send the raw data back to service
    setData(10);
    int data = getData();
    return data;
}

void Gyro::setData(int data){
    this->data = data;
}

int Gyro::getData(){
    return this->data;
}