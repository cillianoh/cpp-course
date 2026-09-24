#include "person.h"
#include <ostream>

void Person::insert(std::ostream &out) const
{
      out << d_name                 // inserts data of person to ostream 
          << ", " << d_address
          << ", " << d_phone 
          << ", " << d_mass << "\n";
}
