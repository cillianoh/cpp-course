#include "main.ih"

//change arg chars to one string
string argvToString(char *argv)
{
    string argString{};

    for (char const el : string(argv))     //for each char in passed as arg.
        if (el != '\'')
            argString += el;               //if it isnt a '\'' add it to string

    return argString;
}
