// This is just the interface of the corresponding service class

#include "../../hardware/Ihardware/Gyro.h"

#ifndef _gyroservice_h
#define _gyroservice_h

namespace services{
    class GyroService {
        private:    
            hardware::Gyro gyro;
            int raw_data;
            int convertRawDatatoSomeData();
            void setRawData(int raw_data);
        public:
            GyroService();
            int requestData();
            int getRawData();
    };
}

#endif