#include "data.ih"

void Data::display() const
{
    cout << "value is: " << d_pimpl->d_value << '\n';
}
