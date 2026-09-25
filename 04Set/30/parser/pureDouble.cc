#include "parser.ih"

// convert string to double, returning true if all chars converted. If it's
// also an int set d_integral as true
bool Parser::pureDouble(double *dest, string const &str)
{
    size_t pos;
    *dest = stod(str, &pos);         // transfer to double and find last char

                                     // false if string has ".", "e" or "E"
    d_integral = str.find_first_of(".eE") == string::npos;

    return pos == str.length();      // true if all chars in string convereted
}
