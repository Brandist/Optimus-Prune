#include "slam/Slam.h"
using namespace SLAM;

/* The main SLAM loop
    the map initalisation containing the lidar, gps and IMU data
        - the map will be an object that is used for pathfinding
        - the map contains points (vectors) containing the lidar data
            - each type of vector has a label indicating if its a wall, possible path, begin and end point (optional)
        - TODO: Implement the SLAM math functions (odometry, landmarks) output and make it visual in the map 
    The slam process should include the following:
        - map building and updating
        - Odometry
            - lidar, IMU
        - the output should be included in the map building as well */
Slam::Slam(){}

// make instances of the map and ekf classes
void Slam::init(){
    this->slam_map = map::Map();
    this->ekf = EKF::Ekf();
}

// initialise the GPS variable 
void Slam::initGPSData(float x, float y, float z){
    setGPSData(Eigen::Vector3f(x,y,z));
}

// initialise the Lidar variable 
void Slam::initLidarData(std::vector<float> x, std::vector<float> y, std::vector<float> z){
    int matrix_size = x.size();
    Eigen::Matrix3Xf mat(3, matrix_size);

    for (int i=0; i<matrix_size; i++){
        float temp_x = x.at(i);
        float temp_y = y.at(i);
        float temp_z = z.at(i);
        Eigen::Vector3f vec(temp_x, temp_y, temp_z);
        mat.col(i) = vec;
    }

    setLidarData(mat);
}

// slam main loop
bool Slam::start(){
    // set the GPS and lidar data in the map class
    slam_map.setGPSData(getGPSData());
    slam_map.setLidarData(getLidarData());

    // initialise the slam map and the ekf
    // The slam_map init should be looked at still, at the moment it initialises some vectors
        // this might not be the place
    slam_map.init();
    ekf.init(slam_map.getRobotPositionVector(), slam_map.getLidarData());
    // constructor of a_star
    // some_a_star_object.init();

    // slam_map.printMap();

    // start the odometry process
    // these methods are work in progress, some things worth looking into:
        // the order the methods are called
        // where they are called
    // What the methods do is known and explained in the odometry section in the report
    ekf.performOdometry();
    // update the current robot position with the results of odometry
    slam_map.updateRobotPosition(ekf.getRobotPosition());

    slam_map.printMap();

    // ekf.performLandmarkExtraction();
    // slam_map.updateRobotPosition(ekf.getRobotPosition());

    // here the pathfinding should be called
    // a_star init which will request the set of Nodes (containing all the nodes)
    // a_start calculateOptimalPath will take in the robot_pos and end_node

    // some exception checking here, return false if something went wrong
    return false;
}

// ---------------------------------------------------------------------------------
// ------------------------------ GETTERS AND SETTERS ------------------------------
// ---------------------------------------------------------------------------------
void Slam::setGPSData(Eigen::Vector3f gps_data){
    this->gps_data = gps_data;
}

Eigen::Vector3f Slam::getGPSData(){
    return this->gps_data;
}

void Slam::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Slam::getLidarData(){
    return this->lidar_data;
}