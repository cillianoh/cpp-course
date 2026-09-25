#ifndef INCLUDED_CALCULATOR_
#define INCLUDED_CALCULATOR_
#include "../parser/parser.h"
#include <string>

class Calculator
{
    Parser d_parser;

    double d_lhs;                
    double d_rhs;                 
    char d_op;                     
    bool d_lhsIsInt;                
    bool d_rhsIsInt;

    public:
        void run();                 // run the calculator program

    private:
        bool expression();          // evaluate if the expression is valid

                                    // evaluate if valid no. is passed and 
                                    // assign values
        bool number(double *dest, bool *isInt);
        bool getOperator();         // evaluate if valid operator and assign 
        void evaluate();            // evaluate parsed expression and output
};

#endif
