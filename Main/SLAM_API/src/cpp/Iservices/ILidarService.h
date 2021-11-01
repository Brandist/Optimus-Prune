// This is just the interface of the corresponding service class
#include <Eigen/Core>
#include "../Ihardware/Lidar.h"

#ifndef _lidarservice_h
#define _lidarservice_h

class LidarService {
    private:
        Lidar lidar;
        int raw_data;
    public:
        LidarService();
        Eigen::Matrix3Xf convertRawDataToMatrix();
        Eigen::Matrix3Xf requestData();
        void setRawData(int raw_data);
        int getRawData();
};

#endif