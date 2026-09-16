#include "main.ih"

//sets second arg as seed if 2 or more args provided, else uses time
void rSeed(int argc, char **argv)
{
    if (argc < 3)                       //if more than 2 args
                                        //use time as seed
        srand(static_cast<unsigned>(time(nullptr)));
    else
                                        //else use arg 2
        srand(atoi(argv[2]));
}
