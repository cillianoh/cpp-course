#include "keys.ih"

ostream &Keys::insert(ostream &out) const
{
    return out <<
        "Keys:      " << d_key << ", number of items: " << d_key.length() << 
                                                                        "\n"
        "Deadline: " << d_nDeadline << ", ignored: " << d_nIgnored << "\n";
}
