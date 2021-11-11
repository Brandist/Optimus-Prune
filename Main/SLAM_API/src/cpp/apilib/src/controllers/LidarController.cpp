#include "apilib/Icontrollers/ILidarController.h"

using namespace controllers;

LidarController::LidarController() {

}

/* Output: Matrix or list of vectors, something that SLAM can work with
    TODO:
    - Add some kind of exception handling
 */
Eigen::Matrix3Xf LidarController::requestData(){
    Eigen::Matrix3Xf data = lidar_service.requestData();
    return data;
}
