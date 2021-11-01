// This is just the interface of the corresponding service class

#include "../Ihardware/Gyro.h"

#ifndef _gyroservice_h
#define _gyroservice_h

class GyroService {
    private:    
        Gyro gyro;
    public:
        GyroService();
        bool requestData();
};

#endif