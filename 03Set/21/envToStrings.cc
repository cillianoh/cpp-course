#include "main.ih"

//returns a string array of environmental variables
void envToStrings(string (&array)[], char **envp)
{
                                       //get number of env. variables
    size_t arrayLength = countEnvp(envp);

                                       //for all variables in envp
    for (size_t indx = 0; indx != arrayLength; ++indx)
        array[indx] = envp[indx];      //adds each env variable to array
}
