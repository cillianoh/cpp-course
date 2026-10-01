#ifndef INCLUDED_COPYCAT_
#define INCLUDED_COPYCAT_

#include <cstddef>

class CopyCat
{
    size_t d_size;
    char **d_data;

    public:
        CopyCat();                          // copies environ
        CopyCat(size_t argc, char const *const *argv);
        CopyCat(char const *const *data);   // cp. any environ-like variable

    private:
                                            // copies ntbs and returns pointer to
                                            // new value
        static char *ntbsCopy(char const *ntbs);
                                            // duplicates ntbs and assigns it to
                                            // passed destination
        static void duplicate(char **dest, char const *const *begin);
                                            // calculates the number of pointers
                                            // in array
        static size_t nElements(char const *const *data);
};

#include "copycat1.f"
#include "duplicate.f"

#endif
