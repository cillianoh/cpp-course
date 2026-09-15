#include "main.ih"

int main(int argc, char **argv)
{
    bool ok = structCall(argc, argv);   //outputs arg no. and value, returns
                                        //false if arg does not exist  
    if (ok)                             //if arg exists
        boundCall(argc, argv);          //outputs arg no. and value
}

