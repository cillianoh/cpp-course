#include "calculator.ih"

// test if operator is valid and assign
bool Calculator::getOperator()
{
    string op = d_parser.next();    // parse next substring

                                    // if string is 1 length and a valid op.
    if (op.length() == 1 && op.find_first_of("+-/*%") != string::npos)
    {
        d_op = op[0];               // assign operator and return true
        return true;
    }

    return false;
}
