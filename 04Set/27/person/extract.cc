#include "person.h"
#include <istream>

void Person::extract(std::istream &in) 
{ 
    std::string mass;

    std::getline(in, d_name, ',');       // first CSV is name
    std::getline(in, d_address, ',');    // second is address
    std::getline(in, d_phone, ',');      // third is phone
    std::getline(in, mass);              // last is mass (getline skips '\n')

    d_mass = std::stoul(mass);           // transfer mass to size_t and assign
}
