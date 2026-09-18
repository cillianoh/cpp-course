#include "main.ih"

int main(int argc, char **argv)
{
    if (hasDots(argc, argv))                   //if there is a dot in arguments
        cout << sum(argc, argv, 0.0) << '\n';  //then result is a double
    
    else
        cout << sum(argc, argv, 0) << '\n';       //else result is an int
}
