#include "apilib/Iservices/ILidarService.h"

using namespace services;

LidarService::LidarService() {

}

// Instead of the convertRawDataToMatrix since a matrix instance is not needed
// This does mean that PCL will be included in the talker file as well, resulting in confusing layering between the files
// This might mean that removing the layers might be better in structure, honestly, it already feels bloated and confusing
pcl::PointCloud<pcl::PointXYZ>::Ptr LidarService::requestPCD(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/sfp/Documents/source/repos/Optimus-Prune/Main/SLAM_API/src/cpp/apilib/src/services/pcd/lidar_ilse_hex.pcd", *cloud) == -1){
        PCL_ERROR("Couldn't read the pcd file \n");
    }
    return cloud;
}