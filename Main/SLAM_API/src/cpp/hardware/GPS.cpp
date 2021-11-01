#include <iostream>
#include <string>
// #include <pcl/io/pcd_io.h>
#include "../Ihardware/GPS.h"

using namespace std;

GPS::GPS(){

}

// TODO: 
// - change data type to raw lidar data type
// - remove set method
int GPS::readRawData(){
    // request the other API for reading data, send the raw data back to service
    setData(10);
    int data = getData();
    return data;
}

// raw data
void GPS::setData(int data){
    this->data = data;
}

// raw data
int GPS::getData(){
    return this->data;
}