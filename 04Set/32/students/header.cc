#include "students.ih"

namespace {

    char const variantsHeader[] = R"R(
Legenda:
    Line 1: Student's ID, e-mail and name
    Line 2: Scores per set ('*': unused set)
    Line 3-7: Percentages per set for each variant ('*%': unused set)
    Lines 9-10: Question numbers (D: deadline indicator)
                (line 10: not if #excercises < 10)
    Line 11: Exercise ratings:
            1 - correctly answered exercise   
            ? - questionable (you received 0.5 point)   
            0 - insufficient or not submitted at the deadline
        space - not submitted or submitted after the deadline
    Line 12: Exercise types:
            . - basic exercise
            + - advanced exercise
        space - cancelled exercise

Last item numbers per set:
)R";

    char const heavyHeader[] = R"R(
Legenda:
    Line 1: Student's ID, e-mail and name
    Line 2:  Scores per set ('*': unused set)
    Line 3: Percentages per set ('*%': unused set)
    Lines 6-7: Question numbers (D: deadline indicator)
               (line 7: not if #excercises < 10)
    Line 8: Exercise ratings:
            1 - correctly answered exercise   
            ? - questionable (you received 0.5 point)   
            0 - insufficient or not submitted at the deadline
        space - not submitted or submitted after the deadline
    Line 9: Exercise types:
            . - basic exercise
            + - advanced exercise
        space - cancelled exercise

Last item numbers per set:
)R";

}

void Students::header() const
{
    headerStart();

    d_results << (d_lightweight ? variantsHeader : heavyHeader);

    for (size_t setIdx = 0, end = d_keys.nSets();
            setIdx != end;
                ++setIdx
    )
        d_results << d_keys.nSet(setIdx) << ' ';

    d_results << R"R(

-----------------------------------------------------------------

)R";

}




