CC := g++ -c
CCO := g++ -o

CONT_DIR := controllers
SERV_DIR := services
HARD_DIR := hardware
TARGET := main

SRCS := $(wildcard *.cpp)
COBJS := $(patsubst %.o, $(CONT_DIR)/%.o, GPSController.o GyroController.o LidarController.o)
SOBJS := $(patsubst %.o, $(SERV_DIR)/%.o, GPSService.o GyroService.o LidarService.o)
HOBJS := $(patsubst %.o, $(HARD_DIR)/%.o, GPS.o Gyro.o Lidar.o)

all: compile
	./$(TARGET)

compile: 
	$(CC) $(TARGET).cpp
	$(MAKE) -C $(CONT_DIR)
	$(MAKE) -C $(SERV_DIR)
	$(MAKE) -C $(HARD_DIR)
	$(CCO) $(TARGET) $(TARGET).o $(COBJS) $(SOBJS) $(HOBJS) 

clean:
	find . -type f -name '*.o' -delete
	$(RM) $(TARGET)