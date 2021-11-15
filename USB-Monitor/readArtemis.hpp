#ifndef _readArtemis_h
#define _readArtemis_h

#include <CppLinuxSerial/SerialPort.hpp>
#include <stdio.h>

struct ArtemisData
{
    double aX;
    double aY;
    double aZ;
    double gX;
    double gY;
    double gZ;
    double mX;
    double mY;
    double mZ;
    double imu_degC;
    time_t gps_Time;
    double gps_Lat;
    double gps_Long;
    double gps_Alt;
    double gps_SIV;
    double gps_FixType;
    double gps_GroundSpeed;
    double gps_heading;
    double gps_pDOP;
    double output_Hz;
};

int init();
std::string readArtemis();
int closeConnection();
int sendData(std::string data);
int print(std::string str);
bool is_number(const char c);
bool is_dash(const char c);
void split(std::string &iString, char delim, Out result);


#endif
