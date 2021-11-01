#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "../Ihardware/Lidar.h"

using namespace std;

Lidar::Lidar(){

}

// TODO: 
// - change data type to raw lidar data type
// - remove set method
// - replace dummy data with actual point cloud data 
// - Compile with cmake in order to compile the PCL, see the tutorial
int Lidar::readRawData(){
    // request the other API for reading data, send the raw data back to service
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    
    // if (pcl::io::loadPCDFile<pcl::PointXYZ>("test_pcd.pcd", *cloud) == -1) {
    //     return -1;
    // }
    
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