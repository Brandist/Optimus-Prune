#include "apilib/Iservices/ILidar.h"

using namespace services;

Lidar::Lidar() {

}

pcl::PointCloud<pcl::PointXYZ>::Ptr Lidar::requestPCD(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    // the argument of this function is the path (relative or not) to the pcd file
    // There is a PCD file in the pcd directory here, you can use this for testing
    if (pcl::io::loadPCDFile<pcl::PointXYZ>("/home/sfp/Documents/source/repos/Optimus-Prune/Main/SLAM_API/src/cpp/apilib/src/services/pcd/77239.pcd", *cloud) == -1){
        PCL_ERROR("Couldn't read the pcd file \n");
    }
    return cloud;
}