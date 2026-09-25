#include "students.ih"

void Students::stdHeader() const
{
    headerStart();

    cout << R"(
    Overview of exercises per set:
    ----------------------------  
                    #exercises        
            last    ----------    
    set:      nr    std.  adv.    
    ----------------------------
)";

    for (size_t setIdx = 0, end = d_keys.nSets(); setIdx != end; ++setIdx)
        cout << 
            setw(7)  << (setIdx + 1) << 
            setw(9)  << d_keys.nSet(setIdx) <<
            setw(7)  << d_keys.nStd(setIdx) <<
            setw(6)  << d_keys.nAdv(setIdx) <<
            '\n';
 
    cout << 
        "    ------------------------------------------\n"
        "\n"
        "Legenda ('x+y' x: basic exercises score, y: advanced exercises "
                                                         "score):\n" <<
        setw(12) << "Line 1:" << " Student's name\n" <<
        setw(12) << "Line 2:" << " Deadline percentage (if available)\n" <<
        setw(12) << "Line 3:" << " Total percentage (if different from "
                                                            "deadline)\n" <<
        setw(12) << "Line 4:" << " Scores per set\n" <<
        setw(12) << "Lines 6-9:" << " Percentages for 5, 4, 3 and 2 points "
                                                        "variants\n" <<
        setw(12) << "Lines 11-12:" << " Exercise numbers ('D' indicates the "
                                                    "deadline exercise)\n" <<
        setw(12) << "Line 13:" << " Exercise Ratings:\n"   
        "              1-9: your rating for this exercise\n"   
        "                ?: rating .5 (questionable)\n"   
        "                0: rating 0 (insufficient or not submitted at the "
                                                                "deadline)\n"
        "                .: beyond the deadline: not submitted\n"   
        "                ~: exercise cancelled\n" <<
        setw(12) << "Line 14:" << " Advanced Exercise Indicators:  |\n" <<
        setw(12) << "Line 15:" << " Max. rating per exercise\n"
        "\n"
        "-----------------------------------------------------------------\n"
        "\n";
}
