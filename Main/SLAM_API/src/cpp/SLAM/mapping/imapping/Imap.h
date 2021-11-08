#include <iostream>
#include <iterator>
#include <map>
#include <Eigen/Core>

#ifndef _map_h
#define _map_h

namespace map {
    class Map {
        private:
            std::map<float, float> slam_map;
            int gps_data;
            Eigen::Matrix3Xf lidar_data;
            Eigen::Vector3f robot_position;
            Eigen::Vector3f start_node;
            Eigen::Vector3f end_node;
            Eigen::Matrix3Xf boundary_nodes;
            Eigen::Matrix3Xf possible_path_nodes;

            void initBoundaryNodes();
            void initNodes();
            void setGPSData(int gps_data);
            void setLidarData(Eigen::Matrix3Xf lidar_data);
            void setRobotPosition(Eigen::Vector3f robot_position);
            void setStartNode(Eigen::Vector3f start_node);
            void setEndNode(Eigen::Vector3f end_node);
            void setBoundaryNodes(Eigen::Matrix3Xf boundary_nodes);
            void setPossiblePathNodes(Eigen::Matrix3Xf possible_path_nodes);
        public:
            Map();
            Map(Eigen::Matrix3Xf lidar_data, int gps_data);
            void init();
            void fillMapWithCoordinates();
            void fillMapWithPointCloud();
            void empty();
            void printMap();
            int getGPSData();
            Eigen::Matrix3Xf getLidarData();
            Eigen::Vector3f getRobotPosition();
            Eigen::Vector3f getStartNode();
            Eigen::Vector3f getEndNode();
            Eigen::Matrix3Xf getBoundaryNodes();
            Eigen::Matrix3Xf getPossiblePathNodes(); 
    };
}

#endif