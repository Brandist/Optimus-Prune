#include "apilib/Icontrollers/ILidarController.h"

using namespace controllers;

LidarController::LidarController() {

}

// TODO:
    // - Add exception handling
pcl::PointCloud<pcl::PointXYZ>::Ptr LidarController::requestPCD(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = lidar.requestPCD();
    return cloud;
}