#include "main.ih"

// read a person from cin for the size of the array passed
void readPersons(Person persons[], size_t size)
{
                                     // for all the objects in the array
    for (size_t indx = 0; indx != size; ++indx)
    {                                
        cout << "? ";                // format input
        persons[indx].extract(cin);  // extract person from cin
    }
}
