#include "data.ih"

Data::Data(): data_pimpl(new DataImp()){}

Data::~Data()
{
    delete data_pimpl;
}
