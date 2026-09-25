#include "student.ih"

void Student::scoresPerSet() const
{
    if (d_keys.nSets() <= 1)     // no separate reporting of
        return;                  // scores per set if there's 
                                 // only one set

    d_results << "  Scores per set: ";

    auto flags = d_results.flags();
    d_results.precision(1);

                                // show the scores per set
    for (size_t index = 0; index != d_keys.nSets(); ++index)
    {
        if (not d_keys.used(index))
            d_results.put('*');
        else
        {
            oddEven(d_stdSum[index]);
            d_results.put('+');
            oddEven(d_advSum[index]);
        }
        d_results << ", ";
    }

    d_results << '\n';

    d_results.flags(flags);
}
