#include "calculator.ih"

// checks if number passed is valid and if it is an int
bool Calculator::number(double *dest, bool *isInt)
{
                                    // if the next string parsed is not a no.
                                    // return false, function assigns number 
                                    // to destination by default
    if (d_parser.number(dest) != Parser::NUMBER)
        return false;
    
    *isInt = d_parser.isIntegral(); // set if it is an integral
    
    return true;
}
