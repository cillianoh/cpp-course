#include "line.ih"

bool Line::getLine() 
{
    getline(cin, d_line);              // extract next line

                                       // start of next substring is the first
                                       // non-ws char
    d_pos = d_line.find_first_not_of(" \t");

                                       // return true if line has no ws chars
    return d_pos != string::npos;
}
