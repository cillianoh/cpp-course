#include "main.ih"

int main(int argc, char **argv, char **envp)
{
    size_t nVariables = countEnvp(envp);       //get no. of environ. variables

    string array[nVariables];                  //array of specified elements

    envToStrings(array, envp);                 //update array with envp 
                                               //variables
                                            
    quicksort(array, 0, nVariables);           //sort array
                    
                                               //print all strings in array
    for (size_t indx = 0; indx != nVariables; ++indx)
        cout << array[indx] << '\n';
}
