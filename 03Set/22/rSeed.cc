#include "main.ih"

//sets second arg as seed if 2 or more args provided
void rSeed(int argc, char **argv)
{
    if (argc > 2)               //if 2nd arg exists use as seed
        srand(atoi(argv[2]));
}
