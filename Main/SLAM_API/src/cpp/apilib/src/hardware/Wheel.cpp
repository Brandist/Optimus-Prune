#include "apilib/Ihardware/Wheel.h"

using namespace hardware;

Wheel::Wheel(){

}

/* TODO: 
    - change data type to raw lidar data type
    - remove set method, since its only needed for testing, we dont want to set the data here as a variable
    Raw GPS Data:
    - Latitide
    - Longitude
    - Altitude
    What kind of object? What kind arguments does this need method require?
    - Maybe make an enum with the data contained if no lib is applicable
    - See discord for pic
*/
int Wheel::readRawData(){
    // request the other API for reading data, send the raw data back to service
    setData(10);
    int data = getData();
    return data;
}

void Wheel::setData(int data){
    this->data = data;
}

int Wheel::getData(){
    return this->data;
}