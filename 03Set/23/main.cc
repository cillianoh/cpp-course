#include "main.ih"

int main(int argc, char **argv)
{
    string argString = string(argv[1]);     //transfer arguements to string

    cout << fixText(argString);             //output string with removed
                                            //double chars
}
