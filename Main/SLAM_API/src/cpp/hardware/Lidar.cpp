#include <iostream>
#include <string>
#include "../Ihardware/Lidar.h"

using namespace std;

Lidar::Lidar(){

}

// TODO: 
// - change data type to raw lidar data type
// - remove set method
int Lidar::readRawData(){
    // request the other API for reading data, send the raw data back to service
    setData(10);
    int data = getData();
    return data;
}

// raw data
void Lidar::setData(int data){
    this->data = data;
}

// raw data
int Lidar::getData(){
    return this->data;
}