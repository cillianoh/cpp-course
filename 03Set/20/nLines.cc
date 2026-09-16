#include "main.ih"

// returns no. of lines in istream
size_t nLines()
{
    size_t nLines = 0;
    string line;    

    while (getline(cin, line))         //while theres a new line in istream
        ++nLines;                      //increase no. of lines

    return nLines;                     //return no. of lines
}
