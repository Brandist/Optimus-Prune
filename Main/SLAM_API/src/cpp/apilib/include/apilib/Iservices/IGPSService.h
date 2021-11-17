// This is just the interface of the corresponding service class
#include <iostream>
#include <string>
#include <vector>
#include "apilib/Ihardware/GPS.h"

#ifndef _gpsservice_h
#define _gpsservice_h

namespace services{
    class GPSService {
        private:
            hardware::GPS gps;
            int raw_data;
            void setRawData(int raw_data);
        public:
            GPSService();
            std::vector<float> requestData();
            int getRawData();
    };
}

#endif