#include <iostream>
#include <string>
using namespace std;

// rotate bits passed as arguements by 1 and output as bits, decimal and 
// hexadecimal
int main (int argc, char *argv[])
{
    string bits = argv[1];                            //extract arguements
    string rotation = argv[2];

    size_t nBits = bits.size();                       //calculate no. of bits
    size_t value = stoul(bits, 0, 2);                 //transform to size_t
    size_t mask = (1UL << nBits) - 1;                 //mask of the no. of bits

    size_t newValue = (rotation == "rol" ? 
        (value << 1 | value >> (nBits - 1)) & mask :  //true:rotate left
        (value >> 1 | value << (nBits - 1)) & mask);  //falese:rotate right

    string result;
    for (size_t bit = nBits; bit-- > 0; ){            //for loop to construct
        result += (newValue >> bit) & 1 ? '1' : '0';  //the new bit string
    } 
                                                      //format and output
                                                      //results
    cout << result << ' ' << newValue << ' ' << hex << newValue << '\n';
}
