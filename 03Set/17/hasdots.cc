#include "main.ih"

// checks to see if there is a decimal point in arguments
bool hasDots(int argc, char **argv)
{

    bool isDot = false;

    for(int indx = 1; indx < argc; ++indx)       //for each argument
        for (const char& el: string(argv[indx])) //for each char
            isDot = el == '.' ? true : isDot;    //only change if its a dot
    
    return isDot;
}