#include "main.ih"

bool structCall(int argc, char **argv)
{
    cout << "Using structCall...\n";                  //Usage message
    
    ReturnValues returnValues = combine(argc, argv);  //struct creation
    
    if (returnValues.ok)                              //if requested arg exists
       cout << "Arg. No.: " << returnValues.nr        //output formatted results
            << "\nArg. Value: " << returnValues.value << '\n'; 
    
    return returnValues.ok;                           //return true if arg
                                                      //exists false otherwise
}


