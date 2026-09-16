#include "main.ih"

// sum all arguments and return a double
double sum(int argc, char **argv, double result)
{
    result = 0;

    for(int indx = 0; indx < argc; ++indx)  // for each arguement
        result += atof(argv[indx]);         // add to result

    return result;
}