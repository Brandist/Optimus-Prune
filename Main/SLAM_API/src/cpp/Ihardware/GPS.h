// This is just the interface of the corresponding hardware class

#ifndef _gps_h
#define _gps_h

class GPS {
    private:
        int data;
    public:
        GPS();
        int readRawData();
        void setData(int data);
        int getData();
};

#endif