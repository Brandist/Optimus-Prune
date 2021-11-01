// This is just the interface of the corresponding hardware class

#ifndef _slam_h
#define _slam_h

class Slam {
    private:
        int gps_data;
        int lidar_data;
    public:
        Slam(int gps_data, int lidar_data);
        bool doSomethingWithGPSData();
        bool doSomethingWithLidarData();
        void setGPSData(int gps_data);
        int getGPSData();
        void setLidarData(int lidar_data);
        int getLidarData();
};

#endif