#include "main.ih"

//return a random number (1 or 2) to represent subjects eye colour
int newSubject()
{
    return (rand() % 2) + 1;  //generate a random number (1 or 2)
}
