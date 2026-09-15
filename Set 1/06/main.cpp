#include <iostream>
using namespace std;

// test for whether input is odd or even in six ways
int main()							
{
    size_t value;
    cin >> value;

    cout << (value % 2 ? "odd" : "even") << '\n';   //if remainder 1, odd
                                                    //is true

    cout << (value == ((value / 2) * 2)             //if there's no remainder,
                ? "even" : "odd") << '\n';          //even is true

    cout << (value & 1 ? "odd" : "even") << '\n';   //if last bit is 1,
                                                    //odd is true

    cout << (value == ((value >> 1) << 1)           //if shift changes
                ? "even" : "odd") << '\n';          //last bit, even is false

    cout << ((value | 1) == value                   //if last bit is 1,
                ? "odd" : "even") << '\n';          //no change, odd is true

    cout << ((value ^ 1) == (value + 1)             //if number increases
                ? "even" : "odd") << '\n';          //with xor, even is true
}