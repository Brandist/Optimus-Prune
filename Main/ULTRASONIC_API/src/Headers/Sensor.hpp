#ifndef _ultrasonic_h
#define _ultrasonic_h

//library for the gpio of the pi.
#include<pigpio>

class Sensor
{
private:
    int listenPin;
    int triggerPin;

    static uint32_t rise_tick = 0;    // Pulse rise time tick value
    static uint32_t pulse_width = 0;  // Last measured pulse width (us)

    void Trigger();
    void ReadPulse(int pi, unsigned user_gpio, unsigned level, uint32_t tick);

    
public:
    Sensor(/* args */);
    ~Sensor();
    float ReadSensor();
    
};




#endif