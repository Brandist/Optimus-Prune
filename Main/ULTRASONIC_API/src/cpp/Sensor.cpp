#include "../Headers/Sensor.hpp"

static uint32_t rise_tick = 0;    // Pulse rise time tick value
static uint32_t pulse_width = 0;  // Last measured pulse width (us)
static bool notWaiting = true;

/* Function: Reads the serial output from the sensor and converts it to distance
 * 
 * Output: The distance of the object to the sesor in mm
*/
float Sensor::ReadSensor()
{
}



std::string Sensor::UnitTest(){

    
    float pulseLenght = ReadSensor();
    return ("Pulse length = " + std::to_string(pulseLenght));
}

Sensor::Sensor(int listenPin, int triggerPin)
{
   
   /* serialport = open(port,O_RDWR);
    std::string str;
    std::fstream f;
    f.open(port);
    while(f>>str)
        std::cout<<str<<std::endl;
*/
    //set the pins to input and output
    this->listenPin=listenPin;
    this->triggerPin=triggerPin;

}

Sensor::~Sensor()
{

}