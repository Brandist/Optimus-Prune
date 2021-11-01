#include <iostream>
#include "Icontrollers/IGPSController.h"
#include "Icontrollers/IGyroController.h"
#include "Icontrollers/ILidarController.h"

using namespace std;

int main() {
    GPSController gps_cont;
    GyroController gyro_cont;
    LidarController lidar_cont;

    int d = lidar_cont.requestData();
    cout << d << endl;
}