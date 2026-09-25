#include "students.ih"

void Students::showDeadlineInfo(size_t noExercises, size_t okCount) const
{
    if (d_keys.nDeadline() == 0)
        return;

    d_results << "\n" <<
            okCount << " participants (" <<
                (100.0 * okCount / d_nStudents) << 
                "%) have reached a score of at least " << 
                    Student::MINIMAL_PERCENTAGE << "% of their maximum\n"
            "    obtainable score at the current deadline "
                "(item " << d_keys.nDeadline() << ").\n"
            "\n";

    if (noExercises == d_nStudents)
        return;

    d_results <<
        (d_nStudents - noExercises) << " participants submitted exercises.\n"
        "\n"
        "Of the latter group, " << 
            (100.0 * okCount / (d_nStudents - noExercises)) <<
            "% have reached a score of at least " <<
                Student::MINIMAL_PERCENTAGE << "% of their\n"
        "   maximum obtainable score at the current deadline.\n"
        "\n";
}


