#include "copycat.ih"

// returns the size of the eviron-like variable
size_t CopyCat::nElements(char const *const *data)
{
    char const *const *end = data;

    while (*end)                    // while end is not a 0 pointer
        ++end;                      // increment pointer

    return end - data;              // return length of data
}
