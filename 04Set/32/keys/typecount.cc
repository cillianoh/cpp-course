#include "keys.ih"

void Keys::typeCount()
{
    for (size_t setIdx = 0, begin = 0; setIdx != d_nSet.size(); ++setIdx)
    {
        if (not d_useSet[setIdx])                   // this set is ignored
        {
            d_nIgnored += d_nSet[setIdx] 
                            - (setIdx == 0 ? 0 : d_nSet[setIdx - 1]);
            continue;
        }

        for (size_t end = d_nSet[setIdx]; begin != end; ++begin)
        {
            switch (d_key[begin])
            {
                case '.':
                    ++d_nStd[setIdx];
                break;

                case '+':
                    ++d_nAdv[setIdx];
                break;

                case ' ':
                    ++d_nIgnored;
                    --d_nSet[setIdx];       // reduce the set size
                break;
            }
        }
    }

    d_nItems = d_key.length() - d_nIgnored;
}
