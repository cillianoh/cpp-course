#include "main.ih"

// count chars in a istream
size_t nChars()
{
    size_t nChars = 0; 
    char ch;
     
    while (cin.get(ch))         //while there is a char in istream
        ++nChars;               //increase number of chars by 1
    
    return nChars;              //return number of chars
}
