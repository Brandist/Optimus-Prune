#include "apilib/Icontrollers/ILidarController.h"

using namespace controllers;

LidarController::LidarController() {

}

pcl::PointCloud<pcl::PointXYZ>::Ptr LidarController::requestPCD(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = lidar_service.requestPCD();
    return cloud;
}

/* Output: Matrix or list of vectors, something that SLAM can work with
    TODO:
    - Add some kind of exception handling
 */
Eigen::Matrix3Xf LidarController::requestData(){
    Eigen::Matrix3Xf data = lidar_service.requestData();
    return data;
}
