#include "calculator.ih"

// true if expression is passed
bool Calculator::expression()
{
                                    // if number passed is not valid
    if (not number(&d_lhs, &d_lhsIsInt))
    {
                                    // error and return false
        cout << "arg 1 is not a number\n";    
        return false;
    }

    if (not getOperator())          // if operator passed is not valid
    {
                                    // error and return false
        cout << "arg 2 is not a valid operator\n";
        return false;
    }

                                    // if number passed is not valid
    if (not number(&d_rhs, &d_rhsIsInt))
    {
                                    // error and return false
        cout << "arg 3 is not a number\n";
        return false;
    }

    return true;
}
