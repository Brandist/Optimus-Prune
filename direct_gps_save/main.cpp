#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include <cstddef>
#include <fstream>

const unsigned char UBX_HEADER[] = { 0xB5, 0x62 };
const unsigned char PVT_HEADER[] = { 0x01, 0x07 };

struct NAV_PVT {
    unsigned char cls;
    unsigned char id;
    unsigned short len;
    unsigned int iTOW;          // GPS time of week of the navigation epoch (ms)
    
    unsigned short year;        // Year (UTC) 
    unsigned char month;        // Month, range 1..12 (UTC)
    unsigned char day;          // Day of month, range 1..31 (UTC)
    unsigned char hour;         // Hour of day, range 0..23 (UTC)
    unsigned char minute;       // Minute of hour, range 0..59 (UTC)
    unsigned char second;       // Seconds of minute, range 0..60 (UTC)
    char valid;                 // Validity Flags (see graphic below)
    unsigned int tAcc;          // Time accuracy estimate (UTC) (ns)
    int nano;                   // Fraction of second, range -1e9 .. 1e9 (UTC) (ns)
    unsigned char fixType;      // GNSSfix Type, range 0..5
    char flags;                 // Fix Status Flags
    char flags2;                // 
    unsigned char numSV;        // Number of satellites used in Nav Solution
    
    int lon;                    // Longitude (deg)
    int lat;                    // Latitude (deg)
    int height;                 // Height above Ellipsoid (mm)
    int hMSL;                   // Height above mean sea level (mm)
    unsigned int hAcc;          // Horizontal Accuracy Estimate (mm)
    unsigned int vAcc;          // Vertical Accuracy Estimate (mm)
    
    int velN;                   // NED north velocity (mm/s)
    int velE;                   // NED east velocity (mm/s)
    int velD;                   // NED down velocity (mm/s)
    int gSpeed;                 // Ground Speed (2-D) (mm/s)
    int heading;                // Heading of motion 2-D (deg)
    unsigned int sAcc;          // Speed Accuracy Estimate
    unsigned int headingAcc;    // Heading Accuracy Estimate
    unsigned short pDOP;        // Position dilution of precision
    char flags3;                // Reserved
    char reserved;              // Reserved
    int reserved1to5;           // Reserved
    int headVeh;
    short magDec;
    unsigned short magAcc;
};

NAV_PVT pvt;
int gpsPoint = 0;

int save(){
    std::ofstream saveFile;
    saveFile.open("saveFile.gps", std::ios::app);

    saveFile << ("GPS point: " + std::to_string(gpsPoint) + '\n');
    saveFile << ("class: " + std::to_string(pvt.cls) + '\n' );
    saveFile << ("ID: " + std::to_string(pvt.id) + '\n');
    saveFile << ("Length: " + std::to_string(pvt.len) + '\n');

    saveFile << ("iTOW: " + std::to_string(pvt.iTOW) + '\n');
    saveFile << ("year: " + std::to_string(pvt.year) + '\n');
    saveFile << ("month: " + std::to_string(pvt.month) + '\n');
    saveFile << ("day: " + std::to_string(pvt.day) + '\n');
    saveFile << ("hour: " + std::to_string(pvt.hour) + '\n');
    saveFile << ("minute: " + std::to_string(pvt.minute) + '\n');
    saveFile << ("second: " + std::to_string(pvt.second) + '\n');
    saveFile << ("valid: " + std::to_string(pvt.valid) + '\n');
    saveFile << ("tAcc: " + std::to_string(pvt.tAcc) + '\n');
    saveFile << ("nano: " + std::to_string(pvt.nano) + '\n');
    saveFile << ("fixType: " + std::to_string(pvt.fixType) + '\n');
    saveFile << ("flags: " + std::to_string(pvt.flags) + '\n');
    saveFile << ("reserved1: " + std::to_string(pvt.flags2) + '\n');
    saveFile << ("numSV: " + std::to_string(pvt.numSV) + '\n');

    saveFile << ("lat: " + std::to_string(pvt.lat) + '\n');
    saveFile << ("long: " + std::to_string(pvt.lon) + '\n');
    saveFile << ("height: " + std::to_string(pvt.height) + '\n');
    saveFile << ("hMSL: " + std::to_string(pvt.hMSL) + '\n');
    saveFile << ("hAcc: " + std::to_string(pvt.hAcc) + '\n');
    saveFile << ("vAcc: " + std::to_string(pvt.vAcc) + '\n');

    saveFile << ("velN: " + std::to_string(pvt.velN) + '\n');
    saveFile << ("velE: " + std::to_string(pvt.velE) + '\n');
    saveFile << ("velD: " + std::to_string(pvt.velD) + '\n');
    saveFile << ("gSpeed: " + std::to_string(pvt.gSpeed) + '\n');
    saveFile << ("heading: " + std::to_string(pvt.heading) + '\n');
    saveFile << ("sAcc: " + std::to_string(pvt.sAcc) + '\n');
    saveFile << ("headAcc: " + std::to_string(pvt.headingAcc) + '\n');
    saveFile << ("pDOP: " + std::to_string(pvt.pDOP) + '\n');
    saveFile << ("flags3: " + std::to_string(pvt.flags3) + '\n');
    saveFile << ("reserved0: " + std::to_string(pvt.reserved) + '\n');
    saveFile << ("reserved1to5: " + std::to_string(pvt.reserved1to5) + '\n');
    saveFile << ("headVeh: " + std::to_string(pvt.headVeh) + '\n');
    saveFile << ("magDec: " + std::to_string(pvt.magDec) + '\n');
    saveFile << ("magAcc: " + std::to_string(pvt.magAcc) + "\n\n");


    saveFile.close();

    return 0;
}

void print_pvt(){
    printf("class: %x\n", pvt.cls);
    printf("ID: %x\n", pvt.id);
    printf("Length: %i\n", pvt.len);
    printf("iTOW: %i\n", pvt.iTOW);

    printf("year: %i\n", pvt.year);
    printf("month: %i\n", pvt.month);
    printf("day: %i\n", pvt.day);
    printf("hour: %i\n", pvt.hour);
    printf("minute: %i\n", pvt.minute);
    printf("second: %i\n", pvt.second);
    printf("valid: %i\n", pvt.valid);
    printf("tAcc: %i\n", pvt.tAcc);
    printf("nano: %i\n", pvt.nano);
    printf("fixType: %i\n", pvt.fixType);
    printf("flags: %c\n", pvt.flags);
    printf("reserved1: %c\n", pvt.flags2);
    printf("numSV: %i\n", pvt.numSV);

    printf("lat: %f\n", (pvt.lat/10000000.0f));
    printf("long: %f\n", (pvt.lon/10000000.0f));
    printf("height: %f\n", (pvt.height/1000.0f));
    printf("hMSL: %f\n", (pvt.hMSL/1000.0f));
    printf("hAcc: %f\n", (pvt.hAcc/1000.0f));
    printf("vAcc: %f\n", (pvt.vAcc/1000.0f));

    printf("velN: %i\n", pvt.velN);
    printf("velE: %i\n", pvt.velE);
    printf("velD: %i\n", pvt.velD);
    printf("gSpeed: %i\n", pvt.gSpeed);
    printf("heading: %i\n", pvt.heading);
    printf("sAcc: %i\n", pvt.sAcc);
    printf("headAcc: %d\n", pvt.headingAcc);
    printf("pDOP: %d\n", pvt.pDOP);
    printf("flags3: %d\n", pvt.flags3);
    printf("reserved0: %d\n", pvt.reserved);
    printf("reserved1to5: %d\n", pvt.reserved1to5);
    printf("headVeh: %d\n", pvt.headVeh);
    printf("magDec: %d\n", pvt.magDec);
    printf("magAcc: %d\n\n", pvt.magAcc);
}

void calcChecksum(unsigned char* CK) {
    memset(CK, 0, 2);
    for (int i = 0; i < (int)sizeof(NAV_PVT); i++) {
        CK[0] += ((unsigned char*)(&pvt))[i];
        CK[1] += CK[0];
    }
}

void read_gps_data(){

    struct termios tty;
    memset(&tty, 0, sizeof tty);

    int serial_port = open("/dev/ttyACM0", O_RDWR | O_CREAT);

    // Check for errors
    if (serial_port < 0) {
        printf("Error %i from open: %s\n", errno, strerror(errno));
    }

        // Read in existing settings, and handle any error
    if(tcgetattr(serial_port, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }

    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
    tty.c_cflag |= CS8; // 8 bits per byte (most common)
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes
    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
    tty.c_cc[VTIME] = 10;   
    tty.c_cc[VMIN] = 0;
    // Set in/out baud rate to be 38400
    cfsetispeed(&tty, B38400);
    cfsetospeed(&tty, B38400);

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }

    // Allocate memory for read buffer, set size according to your needs
    unsigned char c;
    memset(&c, '\0', sizeof(c));

    static int fpos = 0;
    static unsigned char checksum[2];
    const int payloadSize = sizeof(NAV_PVT);
    //printf("The size of PVT is: %li\n\n", sizeof(NAV_PVT));
    while(gpsPoint < 1000000000){
        int n = read(serial_port, &c, sizeof(c));

        // Checks if the UBX header is correct
        if ( fpos < 2 ) {
            if ( c == UBX_HEADER[fpos] ) {
                fpos++;
            }
            else {
                fpos = 0;
            }
        }
        else if ( fpos < 4 ) {
            // Checks if the correct message has been recieved
            if (fpos == 2 && c != PVT_HEADER[0]) {
                fpos = 0;
            }
            else if (fpos == 3 && c != PVT_HEADER[1]) {
                fpos = 0;
            }
            else if ( (fpos-2) < payloadSize ) {
                ((unsigned char*)(&pvt))[fpos-2] = c;
                fpos++;
            }
        }
        else {
            // Saves the gps data in PVT
            if ( (fpos-2) < payloadSize ) {
                ((unsigned char*)(&pvt))[fpos-2] = c;
            }
            fpos++;

            if ( fpos == (payloadSize+2) ) {
                calcChecksum(checksum);
            }
            else if ( fpos == (payloadSize+3) ) {       //checksum a
                if ( c != checksum[0] ){
                    fpos = 0;
                }
            }
            else if ( fpos == (payloadSize+4) ) {       //checksum b
                fpos = 0;
                if ( c == checksum[1] ) {
                    print_pvt();
                    save();
                    gpsPoint++;
                }
            }
            else if ( fpos > (payloadSize+4) ) {
                fpos = 0;
            }
        }
    }
}

int main(){
	read_gps_data();
	return 0;
}
