#include "student.ih"

Student::Percentages Student::variant(size_t points, bool reducedSet) const
{
    d_results << "    " << points << " points: ";

    auto flags = d_results.flags();
    d_results.precision(0);

                                        // std. score resulting in 6
    double sixRequirement = points - 2 == 0 ? .5 : points - 2;
   

    size_t nSets = d_keys.nSets();
    size_t nDeadlineSets = d_keys.nDeadlineSets();
    size_t nUnusedSets = d_keys.nUnusedSets();
    size_t nUnusedDeadlineSets = d_keys.nUnusedDeadlineSets();

    Percentages average{ 0 };

    for (size_t setIdx = 0; setIdx != nSets; ++setIdx) // percentage per set
    {
        if (not d_keys.used(setIdx))
        {
            d_results << "  *%,";
            continue;
        }

        double stdScore = d_stdSum[setIdx] / 2.0;   // std score per set (over
                                                    //  all basic exercises) 

                                                    // correct for additional
        stdScore =  stdScore > sixRequirement ?     // basic exercises
                        6 +  (stdScore            - sixRequirement) /
                             (d_keys.nStd(setIdx) - sixRequirement)
                    :
                        6 * stdScore / sixRequirement;

        double perc = 10 * (stdScore + d_advSum[setIdx]);
        
        if (reducedSet)                     // check sets with < 100% score
        {
            size_t maxGrade = d_keys.maxGrade(setIdx);  // max grade this set
            if (maxGrade < 10)
                perc *= 10.0 / maxGrade;            // correct for maximum
        }

        if (perc > 100)
            perc = 100;

        average.all += perc;
        if (setIdx < nDeadlineSets)
            average.deadline += perc;

        d_results << setw(3) << perc << "%,";
    }

    if (nDeadlineSets == 0)
        d_results << '\n';
    else 
    {
        average.all /= (nSets - nUnusedSets);
        average.deadline /= (nDeadlineSets - nUnusedDeadlineSets);

        d_results << " average:" << setw(3) << average.all << "% (D:" << 
                        setw(3) << average.deadline << "%)\n";
    }

    d_results.flags(flags);

    return average;
}


// Assume std. score = 2.5, #std items = 5, adv. score = 1
// 
// ------------------------------------------------------------------------
//                     remaining      partial          std      final
// sixReq:   Exceed 6  std. score    point 6->7       rating    score
// ------------------------------------------------------------------------
//   3         -           -             -             5         7
//   2         .5          3        0.5 / 3   = .17    6.17      8.17
//   1        1.5          4        1.5 / 4   = .37    6.37      8.37
//  .5        2.0          4.5      2.0 / 4.5 = .44    6.44      8.44
// ------------------------------------------------------------------------
