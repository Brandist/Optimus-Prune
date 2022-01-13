
TEST_SOURCES = src/data_output.cpp src/test.cpp src/json_reader.cpp

all:
	
	g++ -Wall -I/usr/include/cppconn -o program main.cpp -L/usr/lib -lmysqlcppconn -ljsoncpp

test:
	g++ -I/usr/include/cppconn -o test $(TEST_SOURCES) -L/usr/lib -lmysqlcppconn -ljsoncpp