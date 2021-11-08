#include <iostream>
#include <iterator>
#include <map>
#include <Eigen/Core>

#ifndef _map_h
#define _map_h

namespace map {
    class Map {
        private:
            int gps_data;
            Eigen::Matrix3Xf lidar_data;
            std::map<float, float> slam_map;
            void setGPSData(int gps_data);
            void setLidarData(Eigen::Matrix3Xf lidar_data);
        public:
            Map();
            Map(Eigen::Matrix3Xf lidar_data, int gps_data);
            void fillMapWithCoordinates();
            void fillMapWithPointCloud();
            void empty();
            void printMap();
            int getGPSData();
            Eigen::Matrix3Xf getLidarData();
    };
}

#endif