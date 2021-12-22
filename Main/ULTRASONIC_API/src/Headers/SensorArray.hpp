#ifndef _sensorarray_h
#define _sensorarray_h

#include"Sensor.hpp"
#include<vector>
#include <iostream>
#include <fstream> 
//#include <config4cpp/Configuration.h>

class SensorArray
{
private:
    std::vector<Sensor> sensors;
    std::vector<Sensor> sensorsBack;
    std::vector<Sensor> sensorsFront;

    Sensor sensorArr[10];

    //>4                        4000
    int triggerDistanceZone1;
    //3-4                       3000
    int triggerDistanceZone2;
    //1-3                       1000
    int triggerDistanceZone3;
    //<1                        0
    int triggerDistanceZone4;

    
    float ReadSensor();
    
    std::string scanFrontarr();
    std::string scanBackarr();

    std::string scanFront();
    std::string scanBack();

public:
    SensorArray(int tooClose);
    ~SensorArray();
    std::string Scan();
    std::string ScanArray();
};




#endif