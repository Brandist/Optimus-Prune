// This is just the interface of the corresponding controller class
#include "../Iservices/IGyroService.h"

#ifndef _gyrocontroller_h
#define _gyrocontroller_h

namespace controllers{
    class GyroController {
        private:
            services::GyroService gyro_service;
        public:
            GyroController();
            int requestData();
    };
}

#endif