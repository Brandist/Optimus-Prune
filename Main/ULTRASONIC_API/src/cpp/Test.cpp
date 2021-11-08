
#include "Headers/Sensor.hpp"
#include<unistd.h>
int main(void){

    Sensor testSensor = Sensor(3,5);
    for (size_t i = 0; i < 10; i++)
    {
        //scan one sensor
        std::string feedback = testSensor.UnitTest();
        std::cout << feedback << std::endl;
        //wait a seconds
        usleep(1000000);
    }
    
    

}