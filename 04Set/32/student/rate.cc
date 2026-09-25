#include "student.ih"

    // rate the items of set `setIdx', starting at item `itemIdx'

size_t Student::rate(size_t setIdx, size_t itemIdx)
{
                                            // index of the next set:  
    size_t end = d_keys.nSet(setIdx);       // # questions in this set

    if (not d_keys.used(setIdx))             // this set is not used
    {
        return end;
    }

    size_t stdSum = 0;
    size_t advSum = 0;

    for(; itemIdx != end; ++itemIdx)
    {
        if (d_keys.ignore(itemIdx))         // ignore this item
            continue;

        size_t score = answer(itemIdx);     // convert rating to score

        if (d_keys.advanced(itemIdx))
            advSum += score;
        else
            stdSum += score;
    }

    d_stdSum[setIdx] = stdSum;
    d_advSum[setIdx] = advSum;

    if (d_verbose)
        d_results << "verbose: set " << setIdx + 1 << ": std sum (x 2) = " << 
                    stdSum << ", adv. sum (x 2) = " << advSum << '\n';

    return end;
}




