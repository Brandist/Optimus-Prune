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
#include "apilib/Ihardware/Lidar.h"

#ifndef _lidarservice_h
#define _lidarservice_h

namespace services{
    class LidarService {
        private:
            hardware::Lidar lidar;
            Eigen::Matrix3Xf convertRawDataToMatrix();
        public:
            LidarService();
            pcl::PointCloud<pcl::PointXYZ>::Ptr requestPCD();
    };
}

#endif