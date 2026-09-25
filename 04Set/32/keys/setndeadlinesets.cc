#include "keys.ih"

void Keys::setNdeadlineSets()
{
    size_t idx = 0;
    for (
        size_t end = nSets(); 
            idx != end and d_nDeadline >= d_nSet[idx];
                ++idx
    )
    {
        if (not d_useSet[idx])
            ++d_nUnusedDeadlineSets;
    }

    d_nDeadlineSets = idx;
}
