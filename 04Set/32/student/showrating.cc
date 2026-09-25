#include "student.ih"

void Student::showRating(size_t first, size_t beyond) const
{
    string const &rating = d_record.back();

    for (size_t index = first; index != beyond; ++index)
    {
        char verdict = rating[index];
        d_results << (verdict == '.' ? ' ' : verdict);
    }

    d_results << " (your ratings)\n";

    for (size_t index = first; index != beyond; ++index)
        d_results << d_keys[index];

    d_results << " (exercise types)\n";
}
