#include "calculator.ih"

void Calculator::evaluate()
{
    switch (d_op){                  // test operator
        case '+':
            cout << d_lhs + d_rhs << '\n';
        break;

        case '-':
            cout << d_lhs - d_rhs << '\n';
        break;

        case '/':                   // if rhs is not 0
            if (d_rhs > 1e-8 || d_rhs < -1e-8)
                cout << d_lhs / d_rhs << '\n';
            else                    // else output error
                cout << "Invalid Expression\n";
        break;
        
        case '*':                
            cout << d_lhs * d_rhs << '\n';
        break;
        
        case '%':                   // if both are ints and greater than 0
            if (d_lhsIsInt && d_rhsIsInt && d_lhs > 0  && d_rhs > 0)
                cout << int(d_lhs) % int(d_rhs) << '\n';
            else
                cout << "Invalid Expression\n";
        break;

        default:
        break;
    }
}
