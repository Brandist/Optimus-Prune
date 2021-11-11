// This is just the interface of the corresponding controller class
#include <Eigen/Core>
#include "../../services/Iservices/ILidarService.h"

#ifndef _lidarcontroller_h
#define _lidarcontroller_h

namespace controllers{
    class LidarController {
        private:
            services::LidarService lidar_service;
        public:
            LidarController();
            Eigen::Matrix3Xf requestData();
    };
}

#endif