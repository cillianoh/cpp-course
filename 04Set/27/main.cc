#include "main.ih"

int main(int argc, char **argv)
{
    size_t size = 5;                 // size of array
    Person persons[size];            // array of persons
    readPersons(persons, size);      // read persons from cin
    printPersons(persons, size);     // insert persons to cout
}
