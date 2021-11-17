#include "readArtemis.hpp"

using namespace mn::CppLinuxSerial;

SerialPort serialport("/dev/ttyUSB0", BaudRate::B_115200);

int main() {
	init();
	collectAndSend();
	closeConnection();
	return 0;
}

// Initialize the serialport 
int init() {
	serialport.SetTimeout(-1);
	serialport.Open();
	return 0;
}

// Read the Artemis using the serialport
std::string readArtemis() {
	std::string readData;
	serialport.Read(readData);
	return readData;
}

// Close the serialport
int closeConnection() {
	serialport.Close();
	return 0;
}

// TODO
int sendData(struct ArtemisData data) {
	return 0;
}

// Check if character is a number
bool is_number(const char c) {
	return !isblank(c) && isdigit(c);
}

// Check if character is a '-'
bool is_dash(const char c) {
	return !isblank(c) && c == '-';
}

// Split a given string up multiple strings using a delimiter
std::vector<std::string> split(std::string &iString, char delim){
	std::istringstream iss(iString);
	std::string item;
	std::vector<std::string> output;
	int pos = 0;
	while (std::getline(iss, item, delim)) {
		output.push_back(item);
	}
	return output;
}

// Fill up de struct with the data
void putDataInStruct(std::string &iString, char delim, struct ArtemisData &data){
	std::vector<std::string> VS = split(iString, delim);
	for(int i = 0; i < VS.size(); i++) {
		putItemInStruct(data, i, VS[i]);
	}
}

// Fill up 1 item in the struct
void putItemInStruct(struct ArtemisData &data, int index, std::string &iString) {
	switch (index)
	{
	case 0:
		data.aX = stod(iString);
		break;
	case 1:
		data.aY = stod(iString);
		break;
	case 2:
		data.aZ = stod(iString);
		break;
	case 3:
		data.gX = stod(iString);
		break;
	case 4:
		data.gY = stod(iString);
		break;
	case 5:
		data.gZ = stod(iString);
		break;
	case 6:
		data.mX = stod(iString);
		break;
	case 7:
		data.mY = stod(iString);
		break;
	case 8:
		data.mZ = stod(iString);
		break;
	case 9:
		data.imu_degC = stod(iString);
		break;
	case 10:
		//data. = stod(iString);
		break;
	case 11:
		//data.gps_Time = stod(iString);
		break;
	case 12:
		data.gps_Lat = stod(iString);
		break;
	case 13:
		data.gps_Long = stod(iString);
		break;
	case 14:
		data.gps_Alt = stod(iString);
		break;
	case 15:
		data.gps_SIV = stod(iString);
		break;
	case 16:
		data.gps_FixType = stod(iString);
		break;
	case 17:
		data.gps_GroundSpeed = stod(iString);
		break;
	case 18:
		data.gps_heading = stod(iString);
		break;
	case 19:
		data.gps_pDOP = stod(iString);
		break;
	case 20:
		data.output_Hz = stod(iString);
		break;

	
	default:
		break;
	}
}

void collectAndSend() {
	struct ArtemisData dataToBeSend;
	int fFirstReceivedData = 0;
	std::string combinedString;
	for(int i = 0; i < 1000000000; i++){
		std::string rawData = readArtemis();
		char fc = rawData.at(0);
		if (is_number(fc) || is_dash(fc)) {
			if(fFirstReceivedData != 1) {
				fFirstReceivedData = 1;
				combinedString = combinedString + rawData;
			}
		}
		else {
			if(fFirstReceivedData == 1) {
				fFirstReceivedData = 0;
				putDataInStruct(combinedString, ',', dataToBeSend);
				//This is only for testig purposes
				std::cout << dataToBeSend.aX << std::endl
				<< dataToBeSend.aY << std::endl
				<< dataToBeSend.aZ << std::endl
				<< dataToBeSend.gX << std::endl
				<< dataToBeSend.gY << std::endl
				<< dataToBeSend.gZ << std::endl
				<< dataToBeSend.mX << std::endl
				<< dataToBeSend.mY << std::endl
				<< dataToBeSend.mZ << std::endl
				<< dataToBeSend.imu_degC << std::endl
				<< dataToBeSend.gps_Time << std::endl
				<< dataToBeSend.gps_Lat << std::endl
				<< dataToBeSend.gps_Long << std::endl
				<< dataToBeSend.gps_Alt << std::endl
				<< dataToBeSend.gps_SIV << std::endl
				<< dataToBeSend.gps_FixType << std::endl
				<< dataToBeSend.gps_GroundSpeed << std::endl
				<< dataToBeSend.gps_heading << std::endl
				<< dataToBeSend.gps_pDOP << std::endl
				<< dataToBeSend.output_Hz << std::endl;
				printf("end of stream \n");
			}
			//sendData(dataToBeSend);
		}
	}
}