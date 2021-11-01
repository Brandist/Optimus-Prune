#include <iostream>
#include <string>
#include "../Icontrollers/ILidarController.h"
#include "../Iservices/ILidarService.h"

using namespace std;

LidarController::LidarController() {

}

// Output: Matrix or list of vectors, something that SLAM can work with
// Todo:
// - change output
// - Add some kind of exception handling
int LidarController::requestData(){
    int data = lidar_service.requestData();
    return data;
}
