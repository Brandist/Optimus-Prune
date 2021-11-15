#include "readArtemis.hpp"

using namespace mn::CppLinuxSerial;

SerialPort serialport("/dev/ttyUSB0", BaudRate::B_115200);

int main() {
	init();
	struct ArtemisData dataToBeSend;
	int fFirstReceivedData = 0;
	for(int i = 0; i < 100; i++){
		std::string rawData = readArtemis();
		char fc = rawData.at(0);
		print(rawData);
		if (is_number(fc) || is_dash(fc)) {
			if(fFirstReceivedData != 1) {
				fFirstReceivedData = 1;
				
			}
			print(rawData);
		}
		else {
			if(fFirstReceivedData == 1) {
				fFirstReceivedData = 0;
			}
			sendData(dataToBeSend);
		}
	}
	closeConnection();
	return 0;
}

int init() {
	serialport.SetTimeout(-1);
	serialport.Open();
	return 0;
}

std::string readArtemis() {
	std::string readData;
	serialport.Read(readData);
	return readData;
}

int closeConnection() {
	serialport.Close();
	return 0;
}

int sendData(struct ArtemisData data) {
	return 0;
}

int print(std::string str) {
	std::cout << str << std::endl;
	return 0;
}

bool is_number(const char c) {
	return !isblank(c) && isdigit(c);
}

bool is_dash(const char c) {
	return !isblank(c) && c == '-';
}

vector<string> split(std::string &iString, char delim, Out result){
	std::istringstream iss(iString);
	std::string item;
	while (std::getline(iss, item, delim)) {
		*result++ = item;
	}
}

void putDataInStruct(std::string &iString, char delim, struct ArtemisData & data){
	split(*iString, delim, result)
}