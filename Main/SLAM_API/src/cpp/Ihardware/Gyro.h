// This is just the interface of the corresponding hardware class

#ifndef _gyro_h
#define _gyro_h

class Gyro {
    private:
        int data;
    public:
        Gyro();
        int readRawData();
        void setData(int data);
        int getData();
};

#endif