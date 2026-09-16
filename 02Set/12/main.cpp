#include <iostream>
#include <string>
using namespace std;

// sum the digits of a number until it is only one digit
// state if the final digit is divisible by three
int main(int argc, char *argv[])
{
    string valueString = argv[1];
    
    size_t sum = 0;
    for (char el : valueString)            // first sum of strings digits
        sum += el - '0';

    while (sum >= 10)                 
    {
        size_t value = sum;                // initialise value as sum
        sum = 0;

        for ( ; value != 0; value /= 10)   // sum digits
            sum += value % 10;
    }

    cout << (sum % 3                       // if final value is divisible by 3
            ? "\"not divisible by 3"       // output correct statement
            : "\"divisible by 3");
}