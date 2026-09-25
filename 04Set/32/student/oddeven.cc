#include "student.ih"

void Student::oddEven(size_t value) const
{
    auto flags = d_results.flags();
    d_results.precision(1);

    if (value & 1)      // odd value: show 1 decimal
        d_results << value / 2.;
    else
        d_results << value / 2;

    d_results.flags(flags);
}
