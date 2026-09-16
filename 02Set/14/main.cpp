#include <iostream>
using namespace std;

// compute the square root of a number by estimating it using a given function
int main()							
{
    double input;

    while (cout << "Enter a value to compute the sqrt of (<=0 to stop): ",
           cin >> input, input > 0)            //extract first no.
    {
        double x0 = 0;                         //initialise variables so
        double x1 = 1;                         //for loop can start
                                               //for loop stops when sqrt found
        for (size_t indx = 1; x0 != x1; ++indx)
        {    
            x0 = x1;                           //correctly initialise variables

                                               //implent given formula
            x1 = x0 + (input - x0 * x0) / (2 * x0);

                                               //output formatted step
            cout << indx << ": x0: " << x0 << ", x1 = " << x1
                 << ", sqr is: " << x1 * x1 << '\n';
        }

        cout << "sqrt(" << input << ") is " << x1 << '\n';
                                               //output formatted results

    }
}