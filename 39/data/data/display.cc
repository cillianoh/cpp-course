#include "data.ih"

void DataImp::display() const
{
    cout << "value is: " << data_value << '\n';
}

void Data::display() const
{
    (*data_pimpl).display();
}
