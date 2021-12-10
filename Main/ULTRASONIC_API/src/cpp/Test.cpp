
#include "../Headers/Sensor.hpp"
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
    while (readings < 10)
    {
        //read distance
        for (int i = 0; i < 4; i++)
        {
            read(serial_port, &c, sizeof(c));
            //distance.append(1, static_cast<char>(c));
            distance[i]=c;
            printf("result: %x\n", c);
            printf("resultsdsdsds: %x\n", distance[i]);
        }
        
        readings++;
    }
    close(serial_port);
    std::cout << "All read " << std::endl;
}

int main(void)
{
    std::cout << "making sensor 1 " << std::endl;
    Sensor sensor1 = Sensor("/dev/ttyUSB0");
    
    std::cout << " read sensor 1" << std::endl;
    sensor1.ReadSensor();

    std::cout << "Done... " << std::endl;
    
}