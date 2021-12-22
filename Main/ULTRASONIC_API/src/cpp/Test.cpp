
#include "../Headers/Sensor.hpp"
#include "../Headers/SensorArray.hpp"
//#include<unistd.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <cstddef>
#include <fstream>

void unitTest()
{
    printf("startin\n");
    std::fstream f;
    std::string output;

    struct termios tty;
    int serial_port = open("/dev/ttyUSB0", O_RDWR);

    if (serial_port < 0)
        std::cout << "error" << errno << strerror(errno) << std::endl;

    if (tcgetattr(serial_port, &tty) != 0)
    {
        printf("Error %i from tcgetarr: %s\n", errno, strerror(errno));
    }

//set the bits needed for comunication
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;       // Disable RTS/CTS hardware flow control (most common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;                                                        // Disable echo
    tty.c_lflag &= ~ECHOE;                                                       // Disable erasure
    tty.c_lflag &= ~ECHONL;                                                      // Disable new-line echo
    tty.c_lflag &= ~ISIG;                                                        // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);                                      // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable any special handling of received bytes
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable any special handling of received bytes
    //there might need a change here because of the way of reading the data out
    tty.c_cc[VTIME] = 10;
    tty.c_cc[VMIN] = 4;
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
    unsigned char c;
    memset(&c, '\0', 1);
    int readings = 0;
    char distance[4];
    while (readings < 2)
    {
        //read distance
        for (int i = 0; i < 4; i++)
        {
            read(serial_port, &c, sizeof(c));
            //distance.append(1, static_cast<char>(c));
            distance[i] = c;
            printf("result: %x\n", c);
            //printf("resultsdsdsds: %x\n", distance[i]);
        }
        char dist;
        int checksum;
        if ((distance[0] & 0xff) == 0xff)
        {
            checksum = distance[1] + distance[2] + distance[0] & 0x00ff;
            dist = distance[1] << 4 | distance[2];
            printf("distance? %i\n", dist);
            printf("checsum = %x\n", checksum);
        }
        readings++;
    }
    close(serial_port);
    std::cout << "All read " << std::endl;
}

int main(void)
{
    //unitTest();

// having the sensors not in a list/array/vector/stack whatever you call it
    // std::cout << "making sensor 1 " << std::endl;
    // Sensor sensor1 = Sensor("/dev/ttyUSB0");

    // std::cout << " read sensor 1" << std::endl;
    // sensor1.ReadSensor();

    // std::cout << "making sensor 2 " << std::endl;
    // Sensor sensor2 = Sensor("/dev/ttyUSB1");

    // std::cout << " read sensor 2" << std::endl;
    // sensor2.ReadSensor();
    /*
    std::cout << "making sensor 3 " << std::endl;
    Sensor sensor3 = Sensor("/dev/ttyUSB2");
    
    std::cout << " read sensor 3" << std::endl;
    sensor3.ReadSensor();

    std::cout << "making sensor 4 " << std::endl;
    Sensor sensor4 = Sensor("/dev/ttyUSB3");
    
    std::cout << " read sensor 4" << std::endl;
    sensor4.ReadSensor();

    std::cout << "making sensor 5 " << std::endl;
    Sensor sensor5 = Sensor("/dev/ttyUSB4");
    
    std::cout << " read sensor 5" << std::endl;
    sensor5.ReadSensor();

    std::cout << "making sensor 6 " << std::endl;
    Sensor sensor6 = Sensor("/dev/ttyUSB5");
    
    std::cout << " read sensor 6" << std::endl;
    sensor6.ReadSensor();

    std::cout << "making sensor 7 " << std::endl;
    Sensor sensor7 = Sensor("/dev/ttyUSB6");
    
    std::cout << " read sensor 7" << std::endl;
    sensor7.ReadSensor();

    std::cout << "making sensor 8 " << std::endl;
    Sensor sensor8 = Sensor("/dev/ttyUSB7");
    
    std::cout << " read sensor 8" << std::endl;
    sensor8.ReadSensor();

    std::cout << "making sensor 9 " << std::endl;
    Sensor sensor9 = Sensor("/dev/ttyUSB8");
    
    std::cout << " read sensor 9" << std::endl;
    sensor9.ReadSensor();

    std::cout << "making sensor 10 " << std::endl;
    Sensor sensor10 = Sensor("/dev/ttyUSB9");
    
    std::cout << " read sensor 10" << std::endl;
    sensor10.ReadSensor();
    */
    std::cout << "Making array" << std::endl;
    SensorArray arr = SensorArray(10000);


//Putting the sensors in a vector
    /*std::vector<Sensor> sensorsFront;

    Sensor test = Sensor("/dev/ttyUSB0");
    //test.ReadSensor();
    sensorsFront.push_back(test);
    std::cout << "read sensor 1" << std::endl;
    test.ReadSensor();
    std::cout << "Read sensor 1 array" << std::endl;
    sensorsFront[0].ReadSensor();

    Sensor test2 = Sensor("/dev/ttyUSB1");
    sensorsFront.push_back(test2);
    std::cout << "Read sensor 2 " << std::endl;
    test2.ReadSensor();
    std::cout << "Read sensor 2 array" << std::endl;
    sensorsFront[1].ReadSensor();

    std::cout << "Read sensor 1 array" << std::endl;
    sensorsFront[0].ReadSensor();*/

    std::cout << " scanning array" << std::endl;
    //arr.Scan();
    arr.ScanArray();

    /* this part was testing to put the sensors into an array*/
    // Sensor senarr[10];
    // Sensor test = Sensor("/dev/ttyUSB0");
    // senarr[0] = test;
    // senarr[0].ReadSensor();
    // Sensor test2 = Sensor("/dev/ttyUSB1");
    // senarr[1] = test2;
    // Sensor test3 = Sensor("/dev/ttyUSB2");
    // senarr[2] = test3;
    // Sensor test4 = Sensor("/dev/ttyUSB3");
    // senarr[3] = test4;
    // Sensor test5 = Sensor("/dev/ttyUSB4");
    // senarr[4] = test5;
    // Sensor test6 = Sensor("/dev/ttyUSB5");
    // senarr[5]=test6;
    // Sensor test7 = Sensor("/dev/ttyUSB6");
    // senarr[6]=test7;
    // Sensor test8 = Sensor("/dev/ttyUSB7");
    // senarr[7]=test8;
    // Sensor test9 = Sensor("/dev/ttyUSB8");
    // senarr[8]=test9;
    // Sensor test10 = Sensor("/dev/ttyUSB9");
    // senarr[9]=test10;

    // std::cout << " read sensor 1" << std::endl;
    // senarr[0].ReadSensor();
    // std::cout << " read sensor 2" << std::endl;
    // senarr[1].ReadSensor();
    // std::cout << " read sensor 3" << std::endl;
    // senarr[2].ReadSensor();
    // std::cout << " read sensor 4" << std::endl;
    // senarr[3].ReadSensor();
    // std::cout << " read sensor 5" << std::endl;
    // senarr[4].ReadSensor();
    // std::cout << " read sensor 6" << std::endl;
    // senarr[5].ReadSensor();
    // std::cout << " read sensor 7" << std::endl;
    // senarr[6].ReadSensor();
    // std::cout << " read sensor 8" << std::endl;
    // senarr[7].ReadSensor();
    // std::cout << " read sensor 9" << std::endl;
    // senarr[8].ReadSensor();
    // std::cout << " read sensor 10" << std::endl;
    // senarr[9].ReadSensor();


    std::cout << "Done... " << std::endl;
}