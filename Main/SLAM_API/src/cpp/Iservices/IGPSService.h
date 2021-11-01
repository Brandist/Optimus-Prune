// This is just the interface of the corresponding service class

#include "../Ihardware/GPS.h"

#ifndef _gpsservice_h
#define _gpsservice_h

class GPSService {
    private:
        GPS gps;
    public:
        GPSService();
        int convertRawDataToVectors(int raw_data);
        int requestData();
};

#endif