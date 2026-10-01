#include "charcount.ih"

size_t CharCount::count(std::istream &in = cin)
{
    size_t nChars = 0;                                                  
    char ch;

    while (in.get(ch))              // while there is another char in istream
    {
                                    // add char to charInfo
        charInfo.add(static_cast<unsigned char>(ch));
        ++nChars;                   // increase no. of chars
    }

    return nChars;                  // return no. of chars
}
