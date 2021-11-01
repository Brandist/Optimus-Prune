// This is just the interface of the corresponding controller class
#include <Eigen/Core>
#include "../Iservices/ILidarService.h"

#ifndef _lidarcontroller_h
#define _lidarcontroller_h

class LidarController {
    private:
        LidarService lidar_service;
    public:
        LidarController();
        Eigen::Matrix3Xf requestData();
};

#endif