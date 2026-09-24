#include "person.ih"

void Person::insert(ostream &out) const
{
      out << d_name                 // inserts data of person to ostream 
          << ", " << d_address
          << ", " << d_phone 
          << ", " << d_mass << "\n";
}
