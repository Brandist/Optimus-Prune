#include "../include/test.hpp"

using namespace std;


void test1_create() {
    Data_output* doutput = new Data_output();
    cout << "test1_create succes" << std::endl;
}

void test2_acces_send() {
    Data_output* doutput = new Data_output();

    if (doutput->send("tag", "data") == 1){
        cout << "test2_acces_send succes" << std::endl;
        return;
    };

    cout << "test2_acces_send fail" << std::endl;
}

void test3_read_json() {
    Data_output* doutput = new Data_output();

    
    
}

int main(void)
{

    test1_create();
    test2_acces_send();
    test3_read_json();

}

//gcc main.cpp -L/usr/lib -lstdc++ -o program