#include "main.ih"

//choose what to count depending on arguement and output the formatted results
void wc(char arg)
{
    size_t num{};
    switch (arg)
    {
        case 'c':                 //if arg is c output no. of chars in istream
            num = nChars();
        break;
        
        case 'w':                 //if arg is w output no. of words in istream
            num = nWords();
        break;

        case 'l':                 //if arg is l output no. of lines in istream
            num = nLines();
        break;
        
        default:
        break;
    }

    cout << num << '\n';
}
