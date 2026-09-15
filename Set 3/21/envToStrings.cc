#include "main.ih"

//counts number of environmental variables and adds them to a referenced
//string array
size_t envToStrings(string (&array)[maxEntries], char **envp)
{
    size_t count = 0;
    
                                                //while number of elements in 
                                                //array is less than max elements
                                                //and envp is real
    while (count < maxEntries && envp[count] != nullptr)
    {
        array[count] = envp[count];             //adds each env variable to array
        ++count;
    }

    return count;                                //return no. of strings in array
}
