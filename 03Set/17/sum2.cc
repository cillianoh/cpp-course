#include "main.ih"

// sum all arguments and return a double
double sum(size_t argc, char **argv, double result)
{
    result = 0;

    for (size_t indx = 0; indx != argc; ++indx) // for each arguement
        result += atof(argv[indx]);             // add to result

    return result;
}
