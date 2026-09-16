#include "main.ih"

void boundCall(int argc, char **argv)
{
                                                 //Outputting formated results
                                                 //without defining ReturnValues 
    cout << "Using boundCall ...\n" << "Arg. No.: " 
         << combine(argc, argv).nr << "\nArg. Value: "
         << combine(argc, argv).value << '\n';
}
    
