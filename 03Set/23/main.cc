#include "main.ih"

int main(int argc, char **argv)
{
    string argString = argvToString(argv[1]);
    cout << fixText(argString);
}
