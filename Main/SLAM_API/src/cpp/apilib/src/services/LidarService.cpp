#include "apilib/Iservices/ILidarService.h"

using namespace services;

LidarService::LidarService() {

}

// Instead of the convertRawDataToMatrix since a matrix instance is not needed
// This does mean that PCL will be included in the talker file as well, resulting in confusing layering between the files
// This might mean that removing the layers might be better in structure, honestly, it already feels bloated and confusing
pcl::PointCloud<pcl::PointXYZ>::Ptr LidarService::requestPCD(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/sfp/Documents/source/repos/Optimus-Prune/Main/SLAM_API/src/cpp/apilib/src/services/pcd/wur.pcd", *cloud) == -1){
        PCL_ERROR("Couldn't read the pcd file \n");
    }
    return cloud;
}

// DEPRECATED due to trying to reduce complexity cause of the size of pointcloud
/* The conversion from raw data to SLAM-readable data
 Input: raw Lidar data, from the PCL
 Output: Matrix or list of vectors containing the x y z coordinates */
Eigen::Matrix3Xf LidarService::convertRawDataToMatrix(){
    // raw_data contains all the points in the point cloud, the point data contains x, y, z coordinatess
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/sfp/Documents/source/repos/Optimus-Prune/Main/SLAM_API/src/cpp/apilib/src/services/pcd/lidar_ilse_hex.pcd", *cloud) == -1){
        PCL_ERROR("Couldn't read the pcd file \n");
    }

    // std::cout << cloud->width * cloud->height << std::endl;
    int cols = cloud->width * cloud->height;     
    Eigen::Matrix3Xf mat(3,cols);
    
    int i=0;
    for (const auto& point: *cloud){
        float x = point.x;
        float y = point.y;
        float z = point.z;
        Eigen::Vector3f vec(x, y, z);
        mat.col(i) = vec;
        i++;
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