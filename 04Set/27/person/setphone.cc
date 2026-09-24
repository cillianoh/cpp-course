#include "person.ih"

void Person::setPhone(string const &phone)
{
    if (phone.empty())                  // if empty string passed set as 
                                        // unavailable
        d_phone = " - not available -";     
                                        // if only digits in string, set it
    else if (hasOnly("0123456789", phone))
        d_phone = phone;
    else                                // if invalid form output it
        cout << "A phone number may only contain digits\n";
}
