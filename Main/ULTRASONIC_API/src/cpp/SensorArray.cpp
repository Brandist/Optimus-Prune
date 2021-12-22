#include "../Headers/SensorArray.hpp"

//this function is to read out all sensors once
std::string SensorArray::ScanArray()
{
    
    std::cout << "sensor 1. initionalized = "<<sensorArr[0].initialized << std::endl;
    std::cout << " read sensor 1" << std::endl;
    this->sensorArr[0].ReadSensor();
    std::cout << " read sensor 2" << std::endl;
    sensorArr[1].ReadSensor();
    std::cout << " read sensor 3" << std::endl;
    sensorArr[2].ReadSensor();
    std::cout << " read sensor 4" << std::endl;
    sensorArr[3].ReadSensor();
    std::cout << " read sensor 5" << std::endl;
    sensorArr[4].ReadSensor();
    std::cout << " read sensor 6" << std::endl;
    sensorArr[5].ReadSensor();
    std::cout << " read sensor 7" << std::endl;
    sensorArr[6].ReadSensor();
    std::cout << " read sensor 8" << std::endl;
    sensorArr[7].ReadSensor();
    std::cout << " read sensor 9" << std::endl;
    sensorArr[8].ReadSensor();
    std::cout << " read sensor 10" << std::endl;
    sensorArr[9].ReadSensor();
    return "nall";
}
std::string SensorArray::scanFrontarr()
{
    int distance1 = 0;
    int distance2 = 0;
    std::string whatZone;
    whatZone = "1,0,0";

    for (size_t i = 0; i < 4; i++)
    {
        distance1 = sensorArr[i].ReadSensor();
        distance2 = sensorArr[i + 1].ReadSensor();
        std::cout << "d1 sensor " << i << " : " << distance1 << std::endl;
        std::cout << "d2 sensor " << i + 1 << " : " << distance1 << std::endl;
        if (distance2 != 0 || distance1 != 0)
        {
            //if the distance on one of the two sensors is in a certain zone

            if ((distance2 <= triggerDistanceZone1 && distance2 > triggerDistanceZone2) || (distance1 <= triggerDistanceZone1 && distance1 > triggerDistanceZone2))
            {
                //between 4 and 3 meter
                //return something good
                //  zone,distance1,distance2
                whatZone = "2," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone2 && distance2 > triggerDistanceZone3) || (distance1 <= triggerDistanceZone2 && distance1 > triggerDistanceZone3))
            {
                //between 3 and 1 meter
                //return something good
                whatZone = "3," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone3 && distance2 > triggerDistanceZone4) || (distance1 <= triggerDistanceZone3 && distance1 > triggerDistanceZone4))
            {
                //between 1 and 0 meter
                //return something good
                whatZone = "4," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
        }
    }
    return whatZone;
}
std::string SensorArray::scanBackarr()
{
    int distance1 = 0;
    int distance2 = 0;
    std::string whatZone;
    whatZone = "1,0,0";

    for (size_t i = 6; i < 9; i++)
    {
        distance1 = sensorArr[i].ReadSensor();
        distance2 = sensorArr[i + 1].ReadSensor();
        std::cout << "d1 sensor " << i << " : " << distance1 << std::endl;
        std::cout << "d2 sensor " << i + 1 << " : " << distance1 << std::endl;
        if (distance2 != 0 || distance1 != 0)
        {
            //if the distance on one of the two sensors is in a certain zone

            if ((distance2 <= triggerDistanceZone1 && distance2 > triggerDistanceZone2) || (distance1 <= triggerDistanceZone1 && distance1 > triggerDistanceZone2))
            {
                //between 4 and 3 meter
                //return something good
                //  zone,distance1,distance2
                whatZone = "2," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone2 && distance2 > triggerDistanceZone3) || (distance1 <= triggerDistanceZone2 && distance1 > triggerDistanceZone3))
            {
                //between 3 and 1 meter
                //return something good
                whatZone = "3," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone3 && distance2 > triggerDistanceZone4) || (distance1 <= triggerDistanceZone3 && distance1 > triggerDistanceZone4))
            {
                //between 1 and 0 meter
                //return something good
                whatZone = "4," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
        }
        // if(sensorArr[i].initialized){

        // }
    }
    return whatZone;
}

//TODO: make it more modular
//this function is to read out all sensors and see if there are obstacles in sensor pairs
std::string SensorArray::Scan()
{

    //the list is already irganized inf1,f2,f3...b1,b2,b3...
    //so sensor[0] and sensor[1] will be grouped together
    //but only when they both contain a f or a b indicating front and back

    //what if i use two lists.one back and one front. then two funtions that scan front or back
    //whit funtion will just call those two funtions.... yeah!

    //cycle through every sensor. sensor 1 is grouped with 2. sensor 2 with 3
    /*  
           [   1   ] [   3   ]   
            []---[]---[]---[]---[]
                [   2   ] [   4   ]
    */

    //from sensors[0] and sensors[1]
    //so sensors[i] and sensors[i+1]
    //this means that have to check for size-1
    std::string whatZone;
    #ifdef VECTOR
    whatZone = scanBack();
    printf(whatZone.c_str());
    whatZone = scanFront();
    printf(whatZone.c_str());
    #endif
    #ifndef VECTOR
    whatZone = scanBackarr();
    printf(whatZone.c_str());
    whatZone = scanFrontarr();
    printf(whatZone.c_str());
    #endif
    return whatZone;
}

std::string SensorArray::scanFront()
{

    if (sensorsFront.size() < 1)
    {
        printf("thing front it empty\n");
        return "empty\n";
    }

    int distance1 = 0;
    int distance2 = 0;
    std::string whatZone;
    whatZone = "1,0,0";
    printf("start scanning the %i amount of sensors in front\n", sensorsFront.size());
    for (size_t i = 0; i < sensorsFront.size() - 1; i++)
    {
        //sensorDistance = sensors[i].ReadSensor();

        // if (sensorDistance < triggerDistance)
        // {
        //     objectTooClose = true;
        // }

        distance1 = sensorsFront[i].ReadSensor();
        distance2 = sensorsFront[i + 1].ReadSensor();
        std::cout << "d1 sensor " << i << " : " << distance1 << std::endl;
        std::cout << "d2 sensor " << i + 1 << " : " << distance1 << std::endl;
        if (distance2 != 0 || distance1 != 0)
        {
            //if the distance on one of the two sensors is in a certain zone

            if ((distance2 <= triggerDistanceZone1 && distance2 > triggerDistanceZone2) || (distance1 <= triggerDistanceZone1 && distance1 > triggerDistanceZone2))
            {
                //between 4 and 3 meter
                //return something good
                //  zone,distance1,distance2
                whatZone = "2," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone2 && distance2 > triggerDistanceZone3) || (distance1 <= triggerDistanceZone2 && distance1 > triggerDistanceZone3))
            {
                //between 3 and 1 meter
                //return something good
                whatZone = "3," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone3 && distance2 > triggerDistanceZone4) || (distance1 <= triggerDistanceZone3 && distance1 > triggerDistanceZone4))
            {
                //between 1 and 0 meter
                //return something good
                whatZone = "4," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
        }
    }

    return whatZone;
}

std::string SensorArray::scanBack()
{
    if (sensorsBack.size() < 1)
    {
        printf("thing back it empty\n");
        return "empty\n";
    }
    int distance1 = 0;
    int distance2 = 0;
    std::string whatZone;
    whatZone = "1,0,0";

    for (size_t i = 0; i < sensorsBack.size() - 1; i++)
    {
        //sensorDistance = sensors[i].ReadSensor();

        // if (sensorDistance < triggerDistance)
        // {
        //     objectTooClose = true;
        // }

        distance1 = sensorsBack[i].ReadSensor();
        distance2 = sensorsBack[i + 1].ReadSensor();

        if (distance2 != 0 || distance1 != 0)
        {
            //if the distance on one of the two sensors is in a certain zone

            if ((distance2 <= triggerDistanceZone1 && distance2 > triggerDistanceZone2) || (distance1 <= triggerDistanceZone1 && distance1 > triggerDistanceZone2))
            {
                //between 4 and 3 meter
                //return something good
                //  zone,distance1,distance2
                whatZone = "2," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone2 && distance2 > triggerDistanceZone3) || (distance1 <= triggerDistanceZone2 && distance1 > triggerDistanceZone3))
            {
                //between 3 and 1 meter
                //return something good
                whatZone = "3," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
            if ((distance2 <= triggerDistanceZone3 && distance2 > triggerDistanceZone4) || (distance1 <= triggerDistanceZone3 && distance1 > triggerDistanceZone4))
            {
                //between 1 and 0 meter
                //return something good
                whatZone = "4," + std::to_string(distance1) + "," + std::to_string(distance2);
            }
        }
    }

    return whatZone;
}

SensorArray::SensorArray(int tooClose)
{
    //hardcoded to add sensors to the array
    Sensor test = Sensor("/dev/ttyUSB0");
    this->sensorArr[0] = test;
    Sensor test2 = Sensor("/dev/ttyUSB1");
    sensorArr[1] = test2;
    Sensor test3 = Sensor("/dev/ttyUSB2");
    sensorArr[2] = test3;
    Sensor test4 = Sensor("/dev/ttyUSB3");
    sensorArr[3] = test4;
    Sensor test5 = Sensor("/dev/ttyUSB4");
    sensorArr[4] = test5;
    Sensor test6 = Sensor("/dev/ttyUSB5");
    sensorArr[5]=test6;
    Sensor test7 = Sensor("/dev/ttyUSB6");
    sensorArr[6]=test7;
    Sensor test8 = Sensor("/dev/ttyUSB7");
    sensorArr[7]=test8;
    Sensor test9 = Sensor("/dev/ttyUSB8");
    sensorArr[8]=test9;
    Sensor test10 = Sensor("/dev/ttyUSB9");
    sensorArr[9]=test10;

    //here the sensor is read to show it works in this function
    std::cout << " read sensor 1" << std::endl;
    this->sensorArr[0].ReadSensor();

    //push instances of the sensor class into the vector
    // Sensor test = Sensor("/dev/ttyUSB0");
    // //test.ReadSensor();
    // sensorsFront.push_back(test);
    // test.ReadSensor();
    // sensorsFront[0].ReadSensor();

    // Sensor test2 = Sensor("/dev/ttyUSB1");
    // sensorsFront.push_back(test2);

    // Sensor test3 = Sensor("/dev/ttyUSB2");
    // sensorsFront.push_back(test3);

    // Sensor test4 = Sensor("/dev/ttyUSB3");
    // sensorsFront.push_back(test4);

    

    

    triggerDistanceZone1 = 4000;
    //3-4                       3000
    triggerDistanceZone2 = 3000;
    //1-3                       1000
    triggerDistanceZone3 = 1000;
    //<1                        0
    triggerDistanceZone4 = 0;

    //read config from file would be desired

}
SensorArray::~SensorArray() {}
