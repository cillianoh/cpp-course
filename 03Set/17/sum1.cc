#include "main.ih"

// sum all arguments and return an int
int sum(int argc, char **argv, int result)
{
    result = 0;

    for(int indx = 0; indx < argc; ++indx)  //for each argument
        result += atoi(argv[indx]);         // add to result

    return result;
}
