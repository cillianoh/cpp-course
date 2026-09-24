#include "person.ih"

void Person::extract(istream &in) 
{ 
    string mass;

    getline(in, d_name, ',');       // first CSV is name
    getline(in, d_address, ',');    // second is address
    getline(in, d_phone, ',');      // third is phone
    getline(in, mass);              // last is mass (getline skips '\n')

    d_mass = stoul(mass);           // transfer mass to size_t and assign
}
