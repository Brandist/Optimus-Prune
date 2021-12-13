// This is just the interface of the corresponding controller class
#include <iostream>
#include <string>
#include <Eigen/Core>
#include "apilib/Iservices/ILidarService.h"

#ifndef _lidarcontroller_h
#define _lidarcontroller_h

namespace controllers{
    class LidarController {
        private:
            services::LidarService lidar_service;
        public:
            LidarController();
            pcl::PointCloud<pcl::PointXYZ>::Ptr requestPCD();
    };
}

#endif