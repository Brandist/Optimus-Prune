// This is just the interface of the corresponding controller class
#include "../Iservices/IGPSService.h"

#ifndef _gpscontroller_h
#define _gpscontroller_h

namespace controllers{
    class GPSController {
        private:
            services::GPSService gps_service;
        public:
            GPSController();
            int requestData();
    };
}

#endif