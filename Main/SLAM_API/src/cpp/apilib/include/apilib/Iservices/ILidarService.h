#include <iostream>
#include <string>
#include <Eigen/Core>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "apilib/Ihardware/Lidar.h"

#ifndef _lidarservice_h
#define _lidarservice_h

namespace services{
    class LidarService {
        private:
            hardware::Lidar lidar;
            int raw_data;
            Eigen::Matrix3Xf convertRawDataToMatrix();
            void setRawData(int raw_data);
        public:
            LidarService();
            Eigen::Matrix3Xf requestData();
            int getRawData();
    };
}

#endif