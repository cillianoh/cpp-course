#include "parser.ih"

// returns an enum displaying if the next substring is an EOF, number or not
Parser::Return Parser::number(double *dest)
{
    string str = d_line.next();     // extract next substring from line

                                    // if empty return EOLN, else convert
    return str.empty() ? EOLN : convert(dest, str);
}
