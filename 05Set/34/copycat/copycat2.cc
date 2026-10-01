#include "copycat.ih"

CopyCat::CopyCat(size_t argc, char const *const *argv)
:
    d_size(argc),                   // initialising d_size with argc arguement
    d_data(new char *[argc + 1])    // initialising d_data to size of argv
{
    char **dest = d_data;           // new pointer to d_data
                                    
                                    // for range of pointers to constant pointers
                                    // to constant chars in argv 
    for (char const *const *begin = argv, *const *end = argv + argc;
            begin != end; ++begin, ++dest)
    {
        duplicate(dest, begin);
    }

    *dest = 0;                      // end dest with 0-pointer like environ 
}
