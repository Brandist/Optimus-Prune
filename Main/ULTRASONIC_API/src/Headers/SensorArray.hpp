#ifndef _sensorarray_h
#define _sensorarray_h

#include"Sensor.hpp"
#include<vector>
#include <iostream>
#include <fstream> 

class SensorArray
{
private:
    std::vector<Sensor> sensors;
    int triggerDistance;

    float ReadSensor();
    
public:
    SensorArray(int tooClose);
    ~SensorArray();
    bool Scan();
};




#endif