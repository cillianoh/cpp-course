#include "copycat.ih"

CopyCat::CopyCat(char const *const *data)
:
    d_size(nElements(data)),
    d_data(new char *[d_size + 1])
{
    char **dest = d_data;           // creating a pointer to pointers in d_data

                                    // for all the elements in data duplicate 
                                    // NTBS in them
    for (char const *const *begin = data, *const *end = data + d_size;
            begin != end; ++begin, ++dest)
        duplicate(dest, begin);

    *dest = 0;                      // end with 0-pointer like environ
}
