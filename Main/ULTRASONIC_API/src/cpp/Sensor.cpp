#include "../Headers/Sensor.hpp"

/* Function: Reads the serial output from the sensor and converts it to distance
 * 
 * Output: The distance of the object to the sesor in mm
*/
float Sensor::ReadSensor()
{
    
    unsigned char c;
    memset(&c, '\0', sizeof(c));
    char distance[4];
    int dist = 0;
    //read distance. It are 4 bytes so a loop of 4
    for (int i = 0; i < 4; i++)
    {
        read(this->serial_port, &c, sizeof(c));
        distance[i] = c;
        printf("result: %x\n", c);
    }
    int checksum;
    //if the readin starts with ff,it's good
    if((distance[0]&0xff) == 0xff){
        checksum = distance[1]+distance[2]+distance[0] & 0x00ff;
        dist = distance[1]<<4|distance[2];
        printf("distance? %i\n",dist);
        printf("checsum = %x\n",checksum);
    }
    // else if(distance[0]==0)
    // {
    //     for (int i = 0; i < 4; i++)
    // {
    //     read(this->serial_port, &c, sizeof(c));
    //     distance[i] = c;
    //     printf("result: %x\n", c);
    // }
    // int checksum;
    // //if the readin starts with ff,it's good
    // if((distance[0]&0xff) == 0xff){
    //     checksum = distance[1]+distance[2]+distance[0] & 0x00ff;
    //     dist = distance[1]<<4|distance[2];
    //     printf("distance? %i\n",dist);
    //     printf("checsum = %x\n",checksum);
    // }
    // }
    return dist;
}

std::string Sensor::UnitTest()
{
    float distance = ReadSensor();
    return ("distance = " + std::to_string(distance));
}

Sensor::Sensor(std::string usbPort)
{
    this->usbPort = usbPort;
    init();
}

void Sensor::init()
{
    struct termios tty;
    int serial_port = open(usbPort.c_str(), O_RDWR);

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
    tty.c_cc[VMIN] = 0;
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
    this->tty = tty;
    this->serial_port=serial_port;

    initialized = true;
}
Sensor::Sensor(){

}
Sensor::~Sensor()
{
    close(serial_port);
}