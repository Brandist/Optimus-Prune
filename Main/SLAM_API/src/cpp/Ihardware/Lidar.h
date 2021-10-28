// This is just the interface of the corresponding hardware class

#ifndef _lidar_h
#define _lidar_h

class Lidar {
    private:

    public:
        Lidar();
        bool readRawData();
};

#endif