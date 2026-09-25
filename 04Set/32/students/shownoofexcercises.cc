#include "students.ih"

void Students::showNoOfExercises(size_t noExercises) const
{
    if (noExercises == 0)
        return;

    d_results << noExercises << " of the " << d_nStudents << 
            " participants (" << (100.0 * noExercises / d_nStudents) << 
            "%) did not submit exercises.\n"
            "\n";
}
