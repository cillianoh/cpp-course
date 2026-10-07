#ifndef INCLUDED_DATAIMP_
#define INCLUDED_DATAIMP_

#include <iostream>
#include <string>
using namespace std;

class DataImp 
{
    string data_text;
    int data_value;  // in order to help the logic of read.cc and display.cc

    public:

        bool read();
        void display() const; 
};

#endif
