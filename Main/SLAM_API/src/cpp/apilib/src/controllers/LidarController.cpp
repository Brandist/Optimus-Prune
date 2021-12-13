#include "apilib/Icontrollers/ILidarController.h"

using namespace controllers;

LidarController::LidarController() {

}

pcl::PointCloud<pcl::PointXYZ>::Ptr LidarController::requestPCD(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = lidar_service.requestPCD();
    return cloud;
}