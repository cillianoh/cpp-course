#include "main.ih"

//displays all subjects in line with their correct eye colour
void displaySubjects(size_t (&line)[maxLine], size_t nSubjects)
{
                                          //for subjects leaving output eye colour
    for (size_t indx = 0; indx < nSubjects; ++indx)
    {
        cout << indx + 1 << ": ";
        if (line[indx] == 1)              //if value is 1, eye colour is blue
            cout << "blue\n";
        else if (line[indx] == 2)         //if value is 2, eye colour is brown
            cout << "brown\n";
    }   
}
