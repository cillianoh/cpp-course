#include "keys.ih"

void Keys::updateSets(int nItems)
{
    if (nItems < 0)                     // this set is not used
        ++d_nUnusedSets;

    d_useSet.push_back(nItems > 0);     // store whether a set is used or not
    d_nSet.push_back(abs(nItems));      // store the #exercises in this set
                
}
