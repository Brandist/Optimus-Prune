// This is just the interface of the corresponding hardware class
#include <iostream>
#include <string>

#ifndef _wheel_h
#define _wheel_h

namespace hardware{
    class Wheel {
        private:
            int data;
            void setData(int data);
        public:
            Wheel();
            int readRawData();
            int getData();
    };
}

#endif