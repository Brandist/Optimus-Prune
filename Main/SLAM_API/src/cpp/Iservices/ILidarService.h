// This is just the interface of the corresponding service class
#include "../Ihardware/Lidar.h"

#ifndef _lidarservice_h
#define _lidarservice_h

class LidarService {
    private:
        Lidar lidar;
    public:
        LidarService();
        int convertRawDataToVectors(int raw_data);
        int requestData();
};

#endif