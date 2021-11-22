// This is just the interface of the corresponding service class
#include <iostream>
#include <string>
#include <vector>
#include "apilib/Ihardware/Wheel.h"

#ifndef _wheelservice_h
#define _wheelservice_h

namespace services{
    class WheelService {
        private:
            hardware::Wheel wheel;
            int raw_data;
            void setRawData(int raw_data);
        public:
            WheelService();
            int requestData();
            int getRawData();
    };
}

#endif