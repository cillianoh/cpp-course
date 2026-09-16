#include "main.ih"

//compares two strings alphabetically, ignoring case and returns true if lhs
//should be before rhs
bool caseInsensitiveLess(string const &lhs, string const &rhs)
{
                                  //only need to compare to shorter strings length
    size_t len = min(lhs.size(), rhs.size());

    for (size_t indx = 0; indx != len; ++indx)
    {
                                  //make both chars lowercase before comparing
        char l = tolower(static_cast<unsigned char>(lhs[indx]));
        char r = tolower(static_cast<unsigned char>(rhs[indx]));

        if (l != r)               //if chars are different, returns whether l is
                                  //before r
            return l < r;
    }
                                  //if no chars are different, the shorter string
                                  //is first
    return lhs.size() < rhs.size();
}
