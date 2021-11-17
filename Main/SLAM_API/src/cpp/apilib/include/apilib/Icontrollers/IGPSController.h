// This is just the interface of the corresponding controller class
#include <iostream>
#include <string>
#include <vector>
#include "apilib/Iservices/IGPSService.h"

#ifndef _gpscontroller_h
#define _gpscontroller_h

namespace controllers{
    class GPSController {
        private:
            services::GPSService gps_service;
        public:
            GPSController();
            std::vector<float> requestData();
    };
}

#endif