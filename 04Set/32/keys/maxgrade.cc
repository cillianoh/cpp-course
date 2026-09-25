#include "keys.ih"

size_t Keys::maxGrade(size_t setIndex) const
{
    size_t maxStd = d_nStd[setIndex] > 3 ? 7 : 6;   // max grade for the
                                                    // basic exercises

    size_t max = maxStd + d_nAdv[setIndex] * 2;     // add max addable for
                                                    // advanced exercises

    return max >= 10 ? 10 : max;
}
