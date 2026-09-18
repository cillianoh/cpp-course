#include "main.ih"

// checks to see if there is a decimal point in arguments
bool hasDots(size_t argc, char **argv)
{
    for (size_t indx = 1; indx != argc; ++indx)  //for each argument
    {
        for (const char &el: string(argv[indx])) //for each char
        {
            if (el == '.')                       //return true if '.' present
                return true;
        }
    }    
    return false;
}
