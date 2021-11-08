#include "Headers/Sensor.hpp"

static uint32_t rise_tick = 0;    // Pulse rise time tick value
static uint32_t pulse_width = 0;  // Last measured pulse width (us)


/* Function: triggers the sensor and reads the data
 * 
 * Output: 100 if things went wrong
 *         otherwise the pulse length of the sensor
*/
float Sensor::ReadSensor()
{
    bool wasTriggered = Trigger();
    // if (wasTriggered)
    // {
    //     //start reading the pulse
    //     gpioSetAlertFunc(this->listenPin,ReadPulse);
    // }

    return -1;    
}


/* Function: triggers the sensor with a 10 microsecond pulse
 * 
 * Output: returns true if it worked. Else return false
*/
bool Sensor::Trigger()
{
    int validate = gpioTrigger(triggerPin, 10, 1);      //0 if it worked
    return !validate;
}

/* Function: the callback function that will fill the pulse_width variable
 *           The function is called whenever the pin changes state
 * 
 * Output: nothing
 */
void ReadPulse(int gpio, int level, uint32_t tick) {
    printf("GPIO %d became %d at %d", gpio, level, tick);
    if (level == 1) {  // rising edge
        rise_tick = tick;
    }
    else if (level == 0) {  // falling edge
        pulse_width = tick - rise_tick;  // TODO: Handle 72 min wrap-around
    }
}

std::string Sensor::UnitTest(){

    if (gpioInitialise() < 0)
    {
        return "Failed";
    }
    ReadSensor();
}

Sensor::Sensor(int listenPin, int triggerPin)
{
    //this->rise_tick = 0;
    //this->pulse_width = 0;
    //initialize the raspberry pi GPIO
    // needs to go in the main of the main
    

    //set the pins to input and output
    this->listenPin=listenPin;
    this->triggerPin=triggerPin;
    gpioSetMode(listenPin, PI_INPUT);
    gpioSetMode(triggerPin, PI_OUTPUT);
    
    //INP_GPIO(listenPin);
    //INP_GPIO(triggerPin);
    //OUT_GPIO(triggerPin);

}

Sensor::~Sensor()
{
//niet hier want dit terminates de library. Moet wel ergens gebeuren
gpioTerminate();
}