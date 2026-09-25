#include "student.ih"

Student::Percentages Student::variants(bool lightweight, bool reducedSet) 
                                                                        const
{
    d_results << (lightweight ? "  Variants" : "Percentages") << ":\n";

    Percentages average{ variant(5, reducedSet) };

    if (lightweight)
    {
        variant(4, reducedSet);
        variant(3, reducedSet);
        variant(2, reducedSet);
    }

    return average;
}
