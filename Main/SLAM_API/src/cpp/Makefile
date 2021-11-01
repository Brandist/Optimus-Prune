CC := g++ -c
CCO := g++ -o

CONT_DIR := controllers
SERV_DIR := services
HARD_DIR := hardware
SLAM_DIR := SLAM
TARGET := main

SRCS := $(wildcard *.cpp)
COBJS := $(patsubst %.o, $(CONT_DIR)/%.o, GPSController.o GyroController.o LidarController.o)
SOBJS := $(patsubst %.o, $(SERV_DIR)/%.o, GPSService.o GyroService.o LidarService.o)
HOBJS := $(patsubst %.o, $(HARD_DIR)/%.o, GPS.o Gyro.o Lidar.o)
SLAMOBJS := $(patsubst %.o, $(SLAM_DIR)/%.o, slam.o)

all: compile
	./$(TARGET)
	make clean

compile: 
	$(CC) $(TARGET).cpp
	$(MAKE) -C $(CONT_DIR)
	$(MAKE) -C $(SERV_DIR)
	$(MAKE) -C $(HARD_DIR)
	$(MAKE) -C $(SLAM_DIR)
	$(CCO) $(TARGET) $(TARGET).o $(COBJS) $(SOBJS) $(HOBJS) $(SLAMOBJS)

clean:
	find . -type f -name '*.o' -delete
	$(RM) $(TARGET)