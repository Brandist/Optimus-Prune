// This is just the interface of the corresponding service class

#include "../Ihardware/GPS.h"

#ifndef _gpsservice_h
#define _gpsservice_h

namespace services{
    class GPSService {
        private:
            hardware::GPS gps;
            int raw_data;
            int convertRawDataToPosVector();
            void setRawData(int raw_data);
        public:
            GPSService();
            int requestData();
            int getRawData();
    };
}

#endif