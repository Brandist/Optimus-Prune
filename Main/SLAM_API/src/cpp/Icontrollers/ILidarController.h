// This is just the interface of the corresponding controller class
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Iservices/ILidarService.h"

#ifndef _lidarcontroller_h
#define _lidarcontroller_h

class LidarController {
    private:
        LidarService lidar_service;
    public:
        LidarController();
        bool requestData();
};

#endif