
//#include "../Headers/Sensor.hpp"
//#include<unistd.h>
#include<iostream>
#include<fstream>

int main(void){

    
    std::fstream f;
    std::string output;
    //char ot[255];
    f.open("/dev/ttyUSB0"/*,std::fstream::in*/);
    if(f.is_open())
        std::cout<<"is open\n";
    while(f>>std::hex>>output){
        //std::cout<<"before "<<std::endl;
        
        
        //getline(f,output);
    /*  if(!f.good())
            std::cout<<"errors "<<std::endl;*/
        //f.read(ot,255);
        
        
        //std::cout<<"after "<<std::endl;
        std::cout<<"output: "<<std::hex<<output<<std::endl;
    }
    std::cout<<"All read "<<std::endl;

}