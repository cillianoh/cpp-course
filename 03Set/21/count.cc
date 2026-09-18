#include "main.ih"

//counts the number of environment variables
size_t countEnvp(char **envp)
{
    size_t count = 0;
    while (envp[count] != nullptr)      //while there is a new variable
        ++count;                        //increase no. of variables

    return count;
}
