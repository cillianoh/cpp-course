#include "main.ih"

//choose what to count depending on arguement and output the formatted results
void wc(char arg)
{
    switch (arg)
    {
        case 'c':                 //if arg is c output no. of chars in istream
            cout << nChars() << '\n';
        break;
        
        case 'w':                 //if arg is w output no. of words in istream
            cout << nWords() << '\n';
        break;

        case 'l':                 //if arg is l output no. of lines in istream
            cout << nLines() << '\n';
        break;
        
        default:
        break;
    }
}
