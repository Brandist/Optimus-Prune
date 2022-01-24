// This is the interface of the corresponding controller class
#include <iostream>
#include <string>
#include <vector>
#include "apilib/Iservices/IGPS.h"

#ifndef _gpscontroller_h
#define _gpscontroller_h

namespace controllers{
    class GPSController {
        private:
            services::GPS gps;
        public:
            GPSController();
            std::vector<float> requestData();
    };
}

#endif