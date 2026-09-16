#include "main.ih"

int main(int argc, char **argv)
{
    if (argc >= 1)              //if arguement is provided
        wc(*argv[1]);           //run wordcount function
}
