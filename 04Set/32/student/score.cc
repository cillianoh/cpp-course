#include "student.ih"

//static
size_t Student::score(char answer)
{
    switch (answer)
    {
        case '1':
        return 2;

        case '?':
        return 1;

        default:
        return 0;
    }
}
