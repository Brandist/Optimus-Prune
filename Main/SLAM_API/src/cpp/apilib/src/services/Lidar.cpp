#include "apilib/Iservices/ILidar.h"

using namespace services;

Lidar::Lidar() {

}

pcl::PointCloud<pcl::PointXYZ>::Ptr Lidar::requestPCD(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    // the argument of this function is the path (relative or not) to the pcd file
    // /home/sfp/Documents/source/repos/Optimus-Prune/Main/SLAM_API/src/cpp/apilib/src/services/pcd/77239.pcd
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("{path_to_pcd_file}", *cloud) == -1){
        PCL_ERROR("Couldn't read the pcd file \n");
    }
    return cloud;
}