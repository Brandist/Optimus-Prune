#include <iostream>
#include <iterator>
#include <map>
#include <Eigen/Core>

#ifndef _map_h
#define _map_h

/* Struct info: 
    is parent_x & y needed? */
enum NodeType{
        path,
        wall,
        robot,
        start,
        end,
        tree
    };
struct Node {
    float x;
    float y;
    float z;
    float parent_x;
    float parent_y;
    float g_cost;
    float h_cost;
    float f_cost;
    NodeType label;
};

/* Change datatypes:
    - GPS: To struct made by Brandon
    - Lidar: keep in mind what Dmitri is doing
    - Gyro: no clue */
namespace map {
    class Map {
        private:
            std::map<float, float> slam_map;
            Eigen::Vector3f gps_data;
            Eigen::Matrix3Xf lidar_data;
            Eigen::Vector3f robot_position_vector;
            Eigen::Vector3f start_vector;
            Eigen::Vector3f end_vector;
            Node robot_node;
            Node start_node;
            Node end_node;
            Node* nodes;
            int nodes_size;
            void initBoundaryNodes();
            void initNodes();
            void setRobotPositionVector(Eigen::Vector3f robot_position_vector);
            void setStartVector(Eigen::Vector3f start_vector);
            void setEndVector(Eigen::Vector3f end_vector);
            void setBoundaryNodes(Node boundary_nodes);
            void setPossiblePathNodes(Node possible_path_nodes);
            Node* matToNodes();
            Node initRobotPositionNode();
            Node initStartPositionNode();
            Node initEndPositionNode();
            void setAllNodes(Node* node);
            void setRobotNode(Node node);
            void setStartNode(Node node);
            void setEndNode(Node node);
            void setNodesSize(int size);
        public:
            Map();
            Map(Eigen::Matrix3Xf lidar_data, Eigen::Vector3f gps_data);
            void init();
            void fillMapWithCoordinates();
            void fillMapWithPointCloud();
            void empty();
            void printMap();
            void setGPSData(Eigen::Vector3f gps_data);
            void setLidarData(Eigen::Matrix3Xf lidar_data);
            Eigen::Vector3f getGPSData();
            Eigen::Matrix3Xf getLidarData();
            Eigen::Vector3f getRobotPositionVector();
            Eigen::Vector3f getStartVector();
            Eigen::Vector3f getEndVector();
            Node* getAllNodes();
            Node getRobotNode();
            Node getStartNode();
            Node getEndNode();
            int getNodesSize();
            void updateRobotPosition(Eigen::Vector3f new_robot_position);
    };
}

#endif