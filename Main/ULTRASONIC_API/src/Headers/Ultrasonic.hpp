#ifndef _ultrasonic_h
#define _ultrasonic_h

//library for the gpio of the pi.
#include<pigpio>

class Ultrasonic
{
private:
    int listenPin;
    int triggerPin;
public:
    Ultrasonic(/* args */);
    ~Ultrasonic();
    float ReadSensor();
    void Trigger();
};




#endif