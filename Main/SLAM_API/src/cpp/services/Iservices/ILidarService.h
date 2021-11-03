// This is just the interface of the corresponding service class
#include <Eigen/Core>
#include "../../hardware/Ihardware/Lidar.h"

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