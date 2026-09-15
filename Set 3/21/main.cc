#include "main.ih"

int main(int argc, char **argv, char **envp)
{
    string array[maxEntries];                  //array of specified elements

    size_t count = envToStrings(array, envp);  //number of envp variables
                                               //and changing env variables to
                                               //string array
                                            
    quicksort(array, 0, count);                //sort array
                    
                                               //print all strings in array
    for (size_t indx = 0; indx != count; ++indx)
        cout<< array[indx] << '\n';
}
