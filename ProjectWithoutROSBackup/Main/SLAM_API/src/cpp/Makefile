CC := g++ -c
CCO := g++ -o

CONT_DIR := controllers
SERV_DIR := services
HARD_DIR := hardware
SLAM_DIR := SLAM
MAP_DIR  := $(SLAM_DIR)/mapping
EKF_DIR  := $(SLAM_DIR)/EKF

TARGET := main

SRCS := $(wildcard *.cpp)
COBJS := $(patsubst %.o, $(CONT_DIR)/%.o, GPSController.o GyroController.o LidarController.o)
SOBJS := $(patsubst %.o, $(SERV_DIR)/%.o, GPSService.o GyroService.o LidarService.o)
HOBJS := $(patsubst %.o, $(HARD_DIR)/%.o, GPS.o Gyro.o Lidar.o)
SLAMOBJS := $(patsubst %.o, $(SLAM_DIR)/%.o, Slam.o)
MAPOBJS := $(patsubst %.o, $(MAP_DIR)/%.o, Map.o)
EKFOBJS := $(patsubst %.o, $(EKF_DIR)/%.o, Ekf.o)

all: compile
	./$(TARGET)

compile: 
	$(CC) $(TARGET).cpp
	$(MAKE) -C $(CONT_DIR)
	$(MAKE) -C $(SERV_DIR)
	$(MAKE) -C $(HARD_DIR)
	$(MAKE) -C $(SLAM_DIR)
	$(MAKE) -C $(MAP_DIR)
	$(MAKE) -C $(EKF_DIR)
	$(CCO) $(TARGET) $(TARGET).o $(COBJS) $(SOBJS) $(HOBJS) $(SLAMOBJS) $(MAPOBJS) $(EKFOBJS)

clean:
	find . -type f -name '*.o' -delete
	$(RM) $(TARGET)