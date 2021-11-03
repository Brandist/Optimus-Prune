// This is just the interface of the corresponding hardware class

#ifndef _gyro_h
#define _gyro_h

namespace hardware{
    class Gyro {
        private:
            int data;
            void setData(int data);
        public:
            Gyro();
            int readRawData();
            int getData();
    };
}

#endif