// This is just the interface of the corresponding controller class
#include "../Iservices/IGyroService.h"

#ifndef _gyrocontroller_h
#define _gyrocontroller_h

class GyroController {
    private:
        GyroService gyro_service;
    public:
        GyroController();
        bool requestData();
};

#endif