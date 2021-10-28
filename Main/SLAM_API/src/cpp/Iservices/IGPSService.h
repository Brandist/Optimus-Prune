// This is just the interface of the corresponding service class

#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Ihardware/GPS.h"

#ifndef _gpsservice_h
#define _gpsservice_h

class GPSService {
    private:
        GPS gps;
    public:
        GPSService();
        bool requestData();
};

#endif