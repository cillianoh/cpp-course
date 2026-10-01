#include "charcount.ih"

void CharCount::show(char ch)
{
                                    // cast to an unsigned char 
    ch = static_cast<unsigned char>(ch);

                                    // if char is not in list output error
    if (charInfo.locate(ch) != CharInfo::INC)
        cout << '\'' << ch << '\'' << " not present in text\n";
    else
    {
                                    // get the frequency of the char in the
                                    // text
        size_t freq = charInfo.d_list[charInfo.d_charLoc].d_freq;
        
        cout << "char";             // output in specified format

        if (ch == '\n')
            cout << "'\\n'";
        else if (ch == '\t')
            cout << "'\\t'";
        else if (ch >= 32 && ch <= 126)
            cout << '\'' << ch << '\'';
        else                        
                                    // if not printable display decimal value
            cout << static_cast<int>(ch);   

                                    // output the frequency
        cout << ": " << freq << " times\n";
    }
}
