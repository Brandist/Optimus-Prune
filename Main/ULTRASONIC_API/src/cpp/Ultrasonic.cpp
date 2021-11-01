#include "Ultrasonic.hpp"

float ReadSensor()
{
    
}

void Trigger()
{
    
}











Ultrasonic::Ultrasonic(int listenPin, int triggerPin)
{
    int init = gpioInitialise();
    if (init < 0)
    {
        fprintf(stderr, "pigpio initialization failed (%d)\n", pi);
        return init;
    }

    this->listenPin=listenPin;
    this->triggerPin=triggerPin;
    gpioSetMode(listenPin, PI_INPUT);
    gpioSetMode(triggerPin, PI_OUTPUT);
    //INP_GPIO(listenPin);
    //INP_GPIO(triggerPin);
    //OUT_GPIO(triggerPin);

}

Ultrasonic::~Ultrasonic()
{
//niet hier want dit terminates de library. Moet wel ergens gebeuren
gpioTerminate();
}