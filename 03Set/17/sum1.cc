#include "main.ih"

// sum all arguments and return an int
int sum(size_t argc, char **argv, int result)
{
    result = 0;

    for (size_t indx = 0; indx != argc; ++indx) //for each argument
        result += atoi(argv[indx]);             // add to result

    return result;
}
