#include <iostream>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Icontrollers/IGPSController.h"
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Icontrollers/IGyroController.h"
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Icontrollers/ILidarController.h"

using namespace std;

int main() {
    GPSController cont;
    bool d = cont.requestData();
    cout << d << endl;
}