// This is just the interface of the corresponding service class
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Ihardware/Lidar.h"

#ifndef _lidarservice_h
#define _lidarservice_h

class LidarService {
    private:
        Lidar lidar;
    public:
        LidarService();
        bool requestData();
};

#endif