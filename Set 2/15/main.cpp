#include <iostream>
using namespace std;

//input: list of words seperated by spaces
//output: ordered list of every combination of these words.
int main(int argc, char *argv[])
{
    ++argv;                                             //remove function name
    --argc;
    size_t nArgs= argc;                                 //change argc to size_t

    size_t nCombos = 1UL << nArgs;                      //number of combinations
    for (size_t mask = 0; mask < nCombos; ++mask)       //cycle through bits of
    {                                                   //argc (all poss. orders)
        
        cout << mask + 1 << ": ";                       //display index

        for (size_t bit = 0; bit < nArgs; ++bit)        //cycles through bits
        {           
            if (mask >> bit & 1)                        //uses set bits in mask
                cout << argv[bit] << ' ';               //outputs words after it
        }    
        cout << '\n';                                   //Next Line
    }
}
