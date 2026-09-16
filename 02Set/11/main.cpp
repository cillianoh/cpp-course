#include <iostream>
using namespace std;

// input: int; 
//output : value inputted, binary value, numeric value of it's set bits
int main(int argc, char *argv[])
{
    int input = atoi(argv[1]);

    cout << input << " = ";

    size_t nBits = sizeof(input) * 8;               // no. of bits in input 
    bool bits[nBits];

    for (size_t indx = 0; indx != nBits; indx++)    // transferring bits from
    {                                               // input to array
        bits[indx] = (input & 1);                   
        input = input >> 1;
    }

    for (size_t indx = nBits; indx--; )             //outputting bits reversed
        cout << bits[indx];
    

    bool first = true;
    for (size_t indx = nBits; indx--; )
    {  
        if (bits[indx])                              // if there is a bit and 
        {      
            if (first)                               // it is the first one
            {
                cout << " = " << (1 << indx);        // output '=' and value
                first = false;
            }

            else                                     // else (not first)
                cout << " + " << (1 << indx);        // output '+' and value                       
        }
    }
}