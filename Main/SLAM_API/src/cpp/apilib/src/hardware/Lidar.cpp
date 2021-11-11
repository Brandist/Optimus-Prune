#include "apilib/Ihardware/Lidar.h"

using namespace hardware;

Lidar::Lidar(){

}

/* TODO: 
    - change data type to raw lidar data type
    - remove set method
    - replace dummy data with actual point cloud data 
    - Compile with cmake in order to compile the PCL, see the tutorial
    - Think about how I can receive the data from the Lidar (ROS?)
*/
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