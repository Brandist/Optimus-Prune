// Goal: 
    // Reading the data from the Lidar and GPS (IMU) and putting the coordinates a map
#include "slam/imapping/Imap.h"

using namespace map;

Map::Map(){}

// Thinking out loud:
/* get the lidar data as a Matrix object,
    convert the Matrix object to a Node (custom struct) (optional)
    Make a list of nodes. Nodes contain a label giving the Nodes a label
    which is nice for pathfinding and mapping since we can see what a node is.
    And because of the lidar data, we can see if a set of coordinates is far away (indicating a wall or tree) */

// For mapping and pathfinding, matrix objects are converted to custom Nodes which contain labels indicating what they are
// This might not be needed and due to the complexity of conversion, it might not be the best solution
// The Node struct is located in the corresponding header file
// The conversion here is commented and should be researched first if using Nodes for mapping is the best option
void Map::init(){
    Eigen::Matrix3Xf mat = getLidarData();
    // Conversion to nodes is not yet needed or may not be needed at all
    // Node* nodes = matToNodes();
    // std::cout << "s: " << nodes[0].label << std::endl;

    setRobotPositionVector(getGPSData());
    setStartVector(getRobotPositionVector());
    setEndVector(mat.col(mat.cols()-1));

    // Only needed when pathfinding is going to be implemented
    // setAllNodes(nodes);
    // setRobotNode(initRobotPositionNode());
    // setStartNode(initStartPositionNode());
    // setEndNode(initEndPositionNode());

    // delete[] nodes;
}

// Conversion of a matrix to nodes, this is the entire lidar incoming data
Node* Map::matToNodes(){
    Eigen::Matrix3Xf mat = getLidarData();
    setNodesSize(mat.cols());
    int nodes_size = getNodesSize();
    Node* nodes = new Node[nodes_size];

    for (int i=0; i<nodes_size; i++){
        Node node;
        node.x = mat.col(i).x();
        node.y = mat.col(i).y();
        node.z = mat.col(i).z();
        node.parent_x = 0.0;
        node.parent_y = 0.0;
        node.g_cost = 0.0;
        node.h_cost = 0.0;
        node.f_cost = 0.0;
        node.label = path;
        nodes[i] = node;
    }

    return nodes;
}

// Get the GPS vector and convert it to a Node
Node Map::initRobotPositionNode(){
        Node node;
        node.x = getRobotPositionVector().x();
        node.y = getRobotPositionVector().y();
        node.z = getRobotPositionVector().z();
        node.parent_x = 0.0;
        node.parent_y = 0.0;
        node.g_cost = 0.0;
        node.h_cost = 0.0;
        node.f_cost = 0.0;
        node.label = robot;
        return node;
}

// Get the starting position vector of the working day and convert it to a Node
Node Map::initStartPositionNode(){
        Node node;
        node.x = getStartVector().x();
        node.y = getStartVector().y();
        node.z = getStartVector().z();
        node.parent_x = 0.0;
        node.parent_y = 0.0;
        node.g_cost = 0.0;
        node.h_cost = 0.0;
        node.f_cost = 0.0;
        node.label = start;
        return node;
}

// Get the End position (end of the row) and convert it to a Node
Node Map::initEndPositionNode(){
        Node node;
        node.x = getEndVector().x();
        node.y = getEndVector().y();
        node.z = getEndVector().z();
        node.parent_x = 0.0;
        node.parent_y = 0.0;
        node.g_cost = 0.0;
        node.h_cost = 0.0;
        node.f_cost = 0.0;
        node.label = end;
        return node;
}

/* TODO: put the robots current position on a 2d map pure for pathfinding 
 and maybe for 2d map visualisation 
 (Not required, but might be nice) */
void Map::fillMapWithCoordinates(){

}

/* TODO: all the current points in the pointcloud (with their labels (obstacle, path, wall))
 on the 2d map pure for pathfinding, and maybe for 2d map visualisation */
// find a way to make a local map containing every coordinate and label
void Map::fillMapWithPointCloud(){

}

/* called from SLAM containing the new EKF robots position, update it here for the map */
void Map::updateRobotPosition(Eigen::Vector3f new_robot_position){
    setRobotPositionVector(new_robot_position);
}

/* Make the current map empty, not used at the moment */ 
void Map::empty(){

}

/* Print some useful data */
void Map::printMap(){
    std::cout << std::endl << "start node: " << std::endl << getStartVector() << std::endl;
    std::cout << std::endl << "end node: " << std::endl << getEndVector() << std::endl;
    std::cout << std::endl <<  "robots pos: " << std::endl << getRobotPositionVector() << std::endl;
    std::cout << std::endl << "lidar data: " << std::endl << getLidarData() << std::endl;
    std::cout << std::endl << "gps data: " << std::endl << getGPSData() << std::endl;

    std::cout << std::endl << "nodes | x | y | | z | px | py | g | h | f | l |" << std::endl;
    for (int i=0; i<getNodesSize(); i++){
        std::cout << "node " << i << ": " << getAllNodes()[i].x
            << " | " << getAllNodes()[i].y
            << " | " << getAllNodes()[i].z
            << " | " << getAllNodes()[i].parent_x 
            << " | " << getAllNodes()[i].parent_y 
            << " | " << getAllNodes()[i].g_cost 
            << " | " << getAllNodes()[i].h_cost 
            << " | " << getAllNodes()[i].f_cost 
            << " | " << getAllNodes()[i].label 
            << std::endl;
    }
}

// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------

// Might be better to initialise some of this data in the a_star.cpp file
void Map::setRobotPositionVector(Eigen::Vector3f robot_position_vector){
    this->robot_position_vector = robot_position_vector;
}

Eigen::Vector3f Map::getRobotPositionVector(){
    return this->robot_position_vector;
}

void Map::setStartVector(Eigen::Vector3f start_vector){
    this->start_vector = start_vector;
}

Eigen::Vector3f Map::getStartVector(){
    return this->start_vector;
}

void Map::setEndVector(Eigen::Vector3f end_vector){
    this->end_vector = end_vector;
}

Eigen::Vector3f Map::getEndVector(){
    return this->end_vector;
}

void Map::setGPSData(Eigen::Vector3f gps_data){
    this->gps_data = gps_data;
}

Eigen::Vector3f Map::getGPSData(){
    return this->gps_data;
}

void Map::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Map::getLidarData(){
    return this->lidar_data;
}

void Map::setRobotNode(Node node){
    this->robot_node = node;
}

Node Map::getRobotNode(){
    return this->robot_node;
}

void Map::setStartNode(Node node){
    this->start_node = node;
}

Node Map::getStartNode(){
    return this->start_node;
}

void Map::setEndNode(Node node){
    this->end_node = node;
}

Node Map::getEndNode(){
    return this->end_node;
}

void Map::setAllNodes(Node* nodes){
    this->nodes = nodes;
}

Node* Map::getAllNodes(){
    return this->nodes;
}

void Map::setNodesSize(int size){
    this->nodes_size = size;
}

int Map::getNodesSize(){
    return this->nodes_size;
}