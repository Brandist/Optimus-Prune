#include "Sensor.hpp"


/* Function: triggers the sensor and reads the data
 * 
 * Output: 100 if things went wrong
 *         otherwise the pulse length of the sensor
*/
float Sensor::ReadSensor()
{
    bool wasTriggered = Trigger();
    if (wasTriggered)
    {
        //start reading the pulse
    }

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
void Sensor::ReadPulse(int pi, unsigned user_gpio, unsigned level, uint32_t tick) {
    if (level == 1) {  // rising edge
        rise_tick = tick;
    }
    else if (level == 0) {  // falling edge
        pulse_width = tick - rise_tick;  // TODO: Handle 72 min wrap-around
    }
}


Sensor::Ultrasonic(int listenPin, int triggerPin)
{
    //initialize the raspberry pi GPIO
    // needs to go in the main of the main
    int init = gpio_start();
    if (init < 0)
    {
        fprintf(stderr, "pigpio initialization failed (%d)\n", pi);
        return init;
    }

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