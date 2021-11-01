// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include "../Iservices/ILidarService.h"
#include "../Ihardware/Lidar.h"

using namespace std;

LidarService::LidarService() {

}

// This should be the conversion from raw data to SLAM-readable data (which will be a list of vectors I think)
int LidarService::convertRawDataToVectors(int raw_data){
    return raw_data;
}

int LidarService::requestData(){
    // Call the hardware layer to get the raw data
    int data = lidar.readRawData();
    int vector_data = convertRawDataToVectors(data);
    // return a list of vector data
    return vector_data;
}