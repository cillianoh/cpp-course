#include "main.ih"

// returns the number of words in input stream
size_t nWords()
{
    size_t nWords = 0;
    string word;

    while (cin >> word)      //while there is a new word in input stream   
        ++nWords;            //increase word count

    return nWords;           //return the no. of words
}
