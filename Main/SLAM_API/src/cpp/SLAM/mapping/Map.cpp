// Reading the data from the Lidar and GPS (IMU) and putting the coordinates a map
// This still need to be worked out

#include <iostream>
#include <map>
#include <list>
#include <Eigen/Core>
#include "imapping/Imap.h"

using namespace map;

Map::Map(){

}

Map::Map(Eigen::Matrix3Xf lidar_data, int gps_data){
    setLidarData(lidar_data);
    setGPSData(gps_data);
}

/* get the lidar data as a Matrix object,
    convert the Matrix object to a Node (custom struct)
    Make a list of nodes. Nodes contain a label giving the Nodes a label
    which is nice for pathfinding and mapping since we can see what a node is.
    And because of the lidar data, we can see if a set of coordinates is far away (indicating a wall or tree) */
void Map::init(){
    Eigen::Matrix3Xf mat = getLidarData();
    std::cout << mat << std::endl;
    Node nodes[mat.cols()];
    
    for (int i=0; i<mat.cols(); i++){
        Node node;
        node.x = mat.col(i).x();
        node.y = mat.col(i).y();
        node.parent_x = 0.0;
        node.parent_y = 0.0;
        node.g_cost = 0.0;
        node.h_cost = 0.0;
        node.f_cost = 0.0;
        node.label = path_node;
        nodes[i] = node;
    }
}

void Map::initBoundaryNodes(){
    Eigen::Matrix3Xf data = getLidarData();
    /* Given the coordinates of the trees and the requirements, 
     we can calculate the boundary coordinates that the robot cannot drive through
     Give those nodes (coordinates) a high weight value so that the robot knows it will not
     take node into the pathfinding */
    setBoundaryNodes(data);
}

void Map::initNodes(){
    Eigen::Matrix3Xf data = getLidarData();
    /* From the lidar data, check what kind of nodes the robot is allowed to walk on
     This list contains all the nodes the robot is allowed to walk on
     These are all the nodes between the boundary nodes, start and end nodes in the row */
    setPossiblePathNodes(data);
}

/* Plan so far: put the robots current position on a 2d map pure for pathfinding 
 and maybe for 2d map visualisation */
void Map::fillMapWithCoordinates(){

}

/* Plan so far: all the current points in the pointcloud (with their labels (obstacle, path, wall))
 on the 2d map pure for pathfinding, and maybe for 2d map visualisation */
void Map::fillMapWithPointCloud(){

}

/* Print some useful data, not sure what now */
void Map::printMap(){
    std::cout << "start node: " << getStartNode() << ", end node: " << getEndNode() << std::endl;
    std::cout << "robots pos: " << getRobotPosition() << std::endl;
    std::cout << "lidar data: " << getLidarData() << std::endl;
    std::cout << "gps data: " << getGPSData() << std::endl;
    // some print map thing here
}

/* Make the current map empty, (is this needed?) */ 
void Map::empty(){

}

// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------

// Might be better to initialise some of this data in the a_star.cpp file. But who knows eh

void Map::setBoundaryNodes(Eigen::Matrix3Xf boundary_nodes){
    this->boundary_nodes = boundary_nodes;
}

Eigen::Matrix3Xf Map::getBoundaryNodes(){
    return this->boundary_nodes;
}

void Map::setPossiblePathNodes(Eigen::Matrix3Xf possible_path_nodes){
    this->possible_path_nodes = possible_path_nodes;
}

Eigen::Matrix3Xf Map::getPossiblePathNodes(){
    return this->possible_path_nodes;
}

void Map::setRobotPosition(Eigen::Vector3f robot_position){
    this->robot_position = robot_position;
}

Eigen::Vector3f Map::getRobotPosition(){
    return this->robot_position;
}

void Map::setStartNode(Eigen::Vector3f start_node){
    this->start_node = start_node;
}

Eigen::Vector3f Map::getStartNode(){
    return this->end_node;
}

void Map::setEndNode(Eigen::Vector3f end_node){
    this->end_node = end_node;
}

Eigen::Vector3f Map::getEndNode(){
    return this->end_node;
}

void Map::setGPSData(int gps_data){
    this->gps_data = gps_data;
}

int Map::getGPSData(){
    return this->gps_data;
}

void Map::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Map::getLidarData(){
    return this->lidar_data;
}