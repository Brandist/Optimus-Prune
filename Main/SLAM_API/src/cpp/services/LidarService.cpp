// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include <Eigen/Core>
#include "../Iservices/ILidarService.h"
#include "../Ihardware/Lidar.h"

using namespace std;

LidarService::LidarService() {

}

// The conversion from raw data to SLAM-readable data (which will be a list of vectors or a matrix)
// Input: raw Lidar data, from the PCL
// Output: Matrix or list of vectors containing the x y z coordinates
int LidarService::convertRawDataToVectors(int raw_data){
    // raw_data contains all the points in the point cloud, the meta data contains x, y, z coordinates
    // so to make these into vectors the following will need to be done:
    // Amount of cols would be the amounts of points right? Amount of sets of x, y z, so the total divided by 3
    int cols = 1;
    Eigen::Matrix3Xi mat(3,cols);

    for (int i=0; i<mat.cols(); i++){
        int x = 10;
        int y = 10;
        int z = 10;
        Eigen::Vector3i vec(x, y, z);
        mat << vec;
    }   

    cout << mat << endl;
    
    return raw_data;
}

int LidarService::requestData(){
    // Call the hardware layer to get the raw data
    int data = lidar.readRawData();
    int vector_data = convertRawDataToVectors(data);
    // return a list of vector data
    return vector_data;
}