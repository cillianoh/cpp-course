#include "student.ih"

void Student::tens(size_t first, size_t beyond) const
{                      
    size_t deadline = d_keys.nDeadline();

    for (; first++ != beyond; )
        d_results.put(
            first == deadline ? 'D'              :
            first % 10 == 0   ? '0' + first / 10 : ' '
        );

    d_results.put('\n');
}

