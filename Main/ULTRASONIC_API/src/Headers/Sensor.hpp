#ifndef _ultrasonic_h
#define _ultrasonic_h

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <cstddef>
#include <fstream>

class Sensor
{
private:
    std::string usbPort;
    struct termios tty;
    int serial_port;
    std::string sensorPlace;
    

    void init();

public:
bool initialized = false;

    Sensor(std::string usbPort);
    Sensor();
    ~Sensor();
    float ReadSensor();
    std::string UnitTest();
};

#endif