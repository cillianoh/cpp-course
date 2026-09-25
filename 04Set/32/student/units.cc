#include "student.ih"

void Student::units(size_t first, size_t beyond) const
{
    for (; first++ != beyond; )
        d_results.put('0' + first % 10);

    d_results.put('\n');
}
