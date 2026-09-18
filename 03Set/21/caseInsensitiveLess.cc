#include "main.ih"

//compares two strings alphabetically, ignoring case and returns true if lhs
//should be before rhs
bool caseInsensitiveLess(string const &lhs, string const &rhs)
{
                               //only need to compare to shorter strings length
    size_t len = lhs.size() < rhs.size() ? lhs.size() : rhs.size();

    for (size_t indx = 0; indx != len; ++indx)
    {
                               //make both chars lowercase before comparing
        char left = tolower(lhs[indx]);
        char right = tolower(rhs[indx]);

        if (left != right)     //if chars are different, returns whether left
                               // is before right
            return left < right;
    }
                               //if no chars are different, the shorter string
                               //is first
    return lhs.size() < rhs.size();
}
