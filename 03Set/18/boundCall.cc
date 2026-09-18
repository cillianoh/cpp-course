#include "main.ih"

void boundCall(int argc, char **argv)
{
                                                //struct creation
    ReturnValues returnValues = combine(argc, argv);

                                                //Outputting formated results
                                                //without defining ReturnValues
    cout << "Using boundCall ...\n" << "Arg. No.: " 
         << returnValues.nr << "\nArg. Value: "
         << returnValues.value << '\n';
}
    
