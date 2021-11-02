// This is just the interface of the corresponding hardware class

#ifndef _gps_h
#define _gps_h

namespace hardware{
    class GPS {
        private:
            int data;
            void setData(int data);
        public:
            GPS();
            int readRawData();
            int getData();
    };
}

#endif