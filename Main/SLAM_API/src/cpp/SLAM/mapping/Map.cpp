// Reading the data from the Lidar and GPS (IMU) and putting the coordinates a map
// Maybe separate files for landmark extraction, odometry and EKF?
// This still need to be worked out

#include <iostream>
#include <map>
#include <list>
#include <Eigen/Core>
#include "imapping/Imap.h"

using namespace map;

Map::Map(){

}

Map::Map(Eigen::Matrix3Xf lidar_data, int gps_data){
    setLidarData(lidar_data);
    setGPSData(gps_data);

    printMap();
}

void Map::fillMapWithCoordinates(){

}

void Map::fillMapWithPointCloud(){

}

void Map::empty(){

}

void Map::printMap(){
    // Eigen::Matrix3Xf mat = getLidarData();
    // std::cout << mat << std::endl;
    // std::list<Eigen::Vector2f> list_of_vectors;
    
    // for (int i=0; i<mat.cols(); i++){
    //     float x = mat.col(i).x();
    //     float y = mat.col(i).y();
    //     Eigen::Vector2f vec(x, y);
    //     list_of_vectors.push_front(vec);
    // }

    // std::cout << getGPSData() << std::endl;
}

void Map::setGPSData(int gps_data){
    this->gps_data = gps_data;
}

int Map::getGPSData(){
    return this->gps_data;
}

void Map::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Map::getLidarData(){
    return this->lidar_data;
}