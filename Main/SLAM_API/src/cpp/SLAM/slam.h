// SLAM interface

#ifndef _slam_h
#define _slam_h

class Slam {
    private:
        int gps_data;
        int gyro_data;
        int lidar_data;
    public:
        Slam();
        bool start();
        bool doSomethingWithGPSData();
        bool doSomethingWithLidarData();
        bool doSomethingWithGyroData();
        void setGPSData(int gps_data);
        int getGPSData();
        void setLidarData(int lidar_data);
        int getLidarData();
        void setGyroData(int gyro_data);
        int getGyroData();
};

#endif