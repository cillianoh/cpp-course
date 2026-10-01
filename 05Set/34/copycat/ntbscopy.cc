#include "copycat.ih"

char *CopyCat::ntbsCopy(char const *ntbs)
{
                                    // dest is assigned a new char of length 
                                    // ntbs + 1
    char *ret = new char[strlen(ntbs) + 1];

    char *dest = ret;               // create a pointer to ret  
    while (*ntbs)                   // for all the chars up to '\0' 
    {
        *dest = *ntbs;              // assign value from the NTBS
        ++dest;                     // increment pointers
        ++ntbs;
    }

    *dest = '\0';                   // end dest with '\0'

    return ret;
}
