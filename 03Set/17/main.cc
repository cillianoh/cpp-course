#include "main.ih"

int main(int argc, char **argv)
{
    if (hasDots(argc, argv))                   //if there is a dot in arguments
    {
        double result = sum(argc, argv, 0.0);  //then result is a double
        cout << result;  
    }
    else
    {
        int result = sum(argc, argv, 0);       //else result is an int
        cout << result;  
    }
}
