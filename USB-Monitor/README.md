# GPS API

## USB-Monitor

The USB-Monitor is build with the CppLinuxSerial library as it's building foundation. This library makes reading out a USB as easy as setting up some configurations and then starting. This library can:

- Make a connection;
- Read out the USB device;
- Write to the USB device;

## readArtemis

The code that is build upon the CLS library makes a connection with the Artemis and reads out this data. It will then collect that data, convert and place it in a struct. This struct is there to easily refer to the data and later send it over to SLAM.

## Functions:

int init()
- This opens the serialport to the Artemis;

std::string readArtemis()
- This reads the data from the serialport for 255 bytes and then returns this data.
- returns readData : data that has been read;

int closeConnection()
- So far only closes the serialport.

int sendData(struct ArtemisData data)
struct ArtemisData data : The data to be send;
- TODO

bool is_number(const char c)
const char c : The char to be checked;
- Checks if a certain char is a number or not.
returns true or false;

bool is_dash(const char c)
const char c : The char to be checked;
- Checks if a certain char is a dash or not. This has to be checked because the data given could be negative.
returns true or false;

std::vector<std::string> split(std::string &iString, char delim)
std::string &iString : The input string to split;
char delim : The deliminator of the string;
- Splits a string using a deliminator and puts this in a std::vector<std::string>.
returns output : A vector collection of strings;

void putDataInStruct(std::string &iString, char delim, struct ArtemisData &data)
std::string &iString : The input string to put into the struct;
char delim : The deliminator of the string;
struct ArtemisData &data : The struct to put the data in;
- Goes through all the data in the string and asings it to the struct.

void putItemInStruct(struct ArtemisData &data, int index, std::string &iString)
struct ArtemisData &data : The struct to put the data in;
int index : Identifies where the data needs to be put in the struct;
std::string &iString : The data;
- Uses a switch to put the data in the right place in the struct.

void collectAndSend() 
- Collects the data and then sends this to SLAM.