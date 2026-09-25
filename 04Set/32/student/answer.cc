#include "student.ih"

size_t Student::answer(size_t idx) const
{
    return score(d_record.back()[idx]);
}
