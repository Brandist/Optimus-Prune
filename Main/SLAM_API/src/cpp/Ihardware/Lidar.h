// This is just the interface of the corresponding hardware class

#ifndef _lidar_h
#define _lidar_h

class Lidar {
    private:
        int data;
    public:
        Lidar();
        int readRawData();
        void setData(int data);
        int getData();
};

#endif