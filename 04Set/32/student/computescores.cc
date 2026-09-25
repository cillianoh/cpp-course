#include "student.ih"

void Student::computeScores()
{
    size_t begin = 0;           // item index
    
                                // visit/rate all sets
    for (size_t setIdx = 0, end = d_keys.nSets(); setIdx != end; ++setIdx)
        begin = rate(setIdx, begin);    // rate the items of this set,
                                        // start at begin, return the idx
                                        // of the first item of the next set
}










