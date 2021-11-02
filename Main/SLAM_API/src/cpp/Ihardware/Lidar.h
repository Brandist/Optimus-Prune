// This is just the interface of the corresponding hardware class

#ifndef _lidar_h
#define _lidar_h

namespace hardware{
    class Lidar {
        private:
            int data;
            void setData(int data);
        public:
            Lidar();
            int readRawData();
            int getData();
    };
}

#endif