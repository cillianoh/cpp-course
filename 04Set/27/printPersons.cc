#include "main.ih"

// print all persons in array to cout
void printPersons(Person const persons[], size_t size)
{
                                     // for all the objects in the array
    for (size_t indx = 0; indx != size; ++indx)
        persons[indx].insert(cout);  // insert the object to cout
}
