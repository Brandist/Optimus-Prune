// These classes represent the hardware components and receiving their data.
// So readRawData() returns raw GPS data, the service normalises it and the controller checks for errors
// the SLAM folder can then call these from the controller in order to do math shit with the data
#include <iostream>
#include <string>
// #include <pcl/io/pcd_io.h>
#include "../Ihardware/GPS.h"

using namespace std;

GPS::GPS(){

}

int GPS::readRawData(){
    // request the other API for reading data, send the raw data back to service
    setData(10); // dummy data, data type is not accuracte ofcourse
    int data = getData();
    return data;
}

// This should be the raw data from the GPS
// Setting the raw data should not be necessary
void GPS::setData(int data){
    this->data = data;
}

// This should be the raw data from the GPS
int GPS::getData(){
    return this->data;
}