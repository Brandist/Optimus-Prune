// This is just the interface of the corresponding controller class
#include <iostream>
#include <string>
#include <vector>
#include "apilib/Iservices/IWheelService.h"

#ifndef _wheelcontroller_h
#define _wheelcontroller_h

namespace controllers{
    class WheelController {
        private:
            services::WheelService wheel_service;
        public:
            WheelController();
            int requestData();
    };
}

#endif