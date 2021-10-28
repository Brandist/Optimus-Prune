// This is just the interface of the corresponding controller class
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Iservices/IGyroService.h"

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