#include "calculator.ih"

// run the calculator
void Calculator::run()
{
    while (true)         
    {
        cout << "? ";    // formatting
                         
                         // if no non-ws chars read end program
        if (not d_parser.reset())
            break;

                         // if expression is valid
        if (expression())
            evaluate();  // evaluate and output expression      
    } 
}


