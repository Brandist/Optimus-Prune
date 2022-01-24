// This is the interface of the corresponding service class
#include <iostream>
#include <string>
#include <Eigen/Core>
#include <pcl/io/png_io.h>
#include <pcl/point_cloud.h>
#include <pcl/io/point_cloud_image_extractors.h>
#include <pcl/point_types.h>
#include <pcl/PCLImage.h>
#include <pcl/io/file_io.h>
#include <pcl/io/image.h>
#include <pcl/common/common.h>
#include <pcl/io/pcd_io.h>

#ifndef _lidar_h
#define _lidar_h

namespace services{
    class Lidar {
        private:
            Eigen::Matrix3Xf convertRawDataToMatrix();
        public:
            Lidar();
            pcl::PointCloud<pcl::PointXYZ>::Ptr requestPCD();
    };
}

#endif