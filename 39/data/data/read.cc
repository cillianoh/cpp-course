#include "data.ih"

bool DataImp::read()
{   
    cin >> data_value;
    return cin.good();
}

bool Data::read()
{
    return (*data_pimpl).read();
}
