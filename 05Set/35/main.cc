#include "main.ih"

int main(int argc, char **argv)
{
    CharCount charCount;           
                                    // count chars in i stream and construct class 
    cout << charCount.count(cin) << '\n';

                                    // for all the args in argv show how many times they
                                    // appeared in the text
    char ch;
    for (int indx = 1; indx != argc; ++indx)
    {
        ch = *argv[indx];
        charCount.show(ch);
    }
}
