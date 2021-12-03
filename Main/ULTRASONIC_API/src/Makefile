
CC = g++
LIBS = 
CFLAGS =  -Iheaders -std=c++11 #-Wall -Wextra -funroll-loops
OBJS = Ultrasonic.o

all: UltrasonicAPI

UltrasonicAPI: $OBJS
	$(CC) $(OBJS) -g -0 UltrasonicAPI $LIBS

ultrasonic: Ultrasonic.hpp Ultrasonic.cpp
	$(CC) $(CFLAGS) $(LIBS) -c Ultrasonic.cpp -o Ultrasonic.o

unitTest:
	$(CC) -Wall -pthread -o unitTest cpp/Sensor.cpp cpp/Test.cpp -lpigpio -lrt

clean:
	rm unitTest