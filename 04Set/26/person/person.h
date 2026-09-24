#ifndef INCLUDED_PERSON_
#define INCLUDED_PERSON_

#include <string>
#include <iosfwd>

class Person
{
    std::string d_name;             // name of person
    std::string d_address;          // address field
    std::string d_phone;            // telephone number
    size_t      d_mass;             // the mass in kg
                                    
    public:                         // member functions
                                    // members setting data values
        void setName(std::string const &name);
        void setAddress(std::string const &address);
        void setPhone(std::string const &phone);
        void setMass(size_t mass);

                                    // members returning data references
        std::string const &name()     const;
        std::string const &address()  const;
        std::string const &phone()    const;
        size_t mass()                 const;

                                    // inserts data members into the ostream
        void insert(std::ostream &out) const;
                                    // extracts data members from the istream
        void extract(std::istream &in);

    private:                        // private member functions
                                    // returns bool that's true if object
                                    // only has characters in characters
        bool hasOnly(char const *characters, std::string const &object);

};

#include "setname.f"
#include "setaddress.f"
#include "setmass.f"

#include "name.f"
#include "address.f"
#include "phone.f"
#include "mass.f"

#include "hasonly.f"

#endif
