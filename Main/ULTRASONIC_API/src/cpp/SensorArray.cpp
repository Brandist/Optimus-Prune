#include "SensorArray.hpp"
/*
bool Scan()
{
    float sensorDistance;
    bool objectTooClose = false;
    for (size_t i = 0; i < sensors.length(); i++)
    {
        sensorDistance = sensors[i].ReadSensor();
        if (sensorDistance < triggerDistance)
        {
            objectTooClose = true;
        }
    }
    return objectTooClose;
}

SensorArray::SensorArray(int tooClose)
{
    this->triggerDistance = tooClose;

    //read pinout from file
    //option 1
    std::istringstream is_file(config);         //might need to do this different. 

    std::string line;
    while (std::getline(is_file, line))
    {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '='))
        {
            std::string value;
            if (std::getline(is_line, value))
                store_line(key, value);
        }
    }

    //option 2
    /* ifstream pinConfigFile("filelocationnnn");

    while (getline (MyReadFile, myText)) {
        
    }

    pinConfigFile.close();
}
SensorArray::~SensorArray();
*/