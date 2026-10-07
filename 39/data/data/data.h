#ifndef INCLUDED_DATA_
#define INCLUDED_DATA_

#include <string>

class DataImp;

class Data
{
    DataImp *data_pimpl; // pointer to the implementation

    public:
        Data(); // constructors and destructors to avoid memory leaks
        ~Data(); 

        bool read();
        void display() const; 
};
        
#endif
