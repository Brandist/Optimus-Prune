// This is just the interface of the corresponding service class
#include <iostream>
#include <string>
#include <vector>

#ifndef _gps_h
#define _gps_h

namespace services{
    class GPS {
        private:
            int raw_data;
            void setRawData(int raw_data);
        public:
            GPS();
            std::vector<float> requestData();
            int getRawData();
    };
}

#endif