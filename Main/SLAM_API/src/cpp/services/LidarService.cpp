// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc
#include <iostream>
#include <string>
#include <Eigen/Core>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "Iservices/ILidarService.h"
#include "../hardware/Ihardware/Lidar.h"

using namespace services;

LidarService::LidarService() {

}

// TODO: 
// - remove conversion method
/* The conversion from raw data to SLAM-readable data
 Input: raw Lidar data, from the PCL
 Output: Matrix or list of vectors containing the x y z coordinates */
Eigen::Matrix3Xf LidarService::convertRawDataToMatrix(){
    // raw_data contains all the points in the point cloud, the point data contains x, y, z coordinates
    int data = getRawData();
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    // Amount of cols are be the amounts of points. i.e.: Amount of sets of x, y z, so the total divided by 3
    // int cols = cloud->size();
    int cols = 10;     
    Eigen::Matrix3Xf mat(3,cols);
    // int i=0;
    // for (const auto &point: *cloud){
    //     Eigen::Vector3f vec(point.x, point.y, point.z);
    //     mat.col(i) = vec;
    //     i++;
    // }
    for (int i=0; i<mat.cols(); i++){
        float x = i;
        float y = i + 2;
        float z = 1.0;
        Eigen::Vector3f vec(x, y, z);
        mat.col(i) = vec;
    }   

    return mat;
}

Eigen::Matrix3Xf LidarService::requestData(){
    // Call the hardware layer to get the raw data
    setRawData(lidar.readRawData());
    Eigen::Matrix3Xf vector_data = convertRawDataToMatrix();
    return vector_data;
}

void LidarService::setRawData(int raw_data){
    this->raw_data = raw_data;
}

int LidarService::getRawData(){
    return this->raw_data;
}