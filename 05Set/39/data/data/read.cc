#include "data.ih"

bool Data::read()
{   
    d_pimpl->d_text.clear();
    cin >> d_pimpl->d_value;
    return cin.good();
}
