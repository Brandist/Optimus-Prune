#ifndef _ultrasonic_h
#define _ultrasonic_h


#include<iostream>



class Sensor
{
private:
    int listenPin;
    int triggerPin;

    int serialport;

    bool Trigger();
    //void ReadPulse(int gpio, int level, uint32_t tick);

    
public:
    Sensor(int listenPin,int triggerPing);
    ~Sensor();
    float ReadSensor();
    std::string UnitTest();
    //void SetRiseTick(int);
   // uint32_t GetRiseTick();
};




#endif