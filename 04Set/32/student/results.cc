#include "student.ih"

void Student::results(size_t *noExercises, size_t *okCount,
                      bool lightweight, bool reducedSet) const
{
                                // write the student's ID, email, and name 
    d_results << d_id << ' ' << d_email << "  " << d_record.front() << '\n';
    scoresPerSet();
    Percentages average{ variants(lightweight, reducedSet) };

    *noExercises += (average.all == 0 && average.deadline == 0);
    *okCount += (
                    average.deadline >= 
                                static_cast<double>(MINIMAL_PERCENTAGE)
                    || 
                    average.all >= static_cast<double>(MINIMAL_PERCENTAGE)
                );

    d_results << '\n';
    showRatings();
    d_results << "\n"
            "-------------------------------------\n"
            "\n";
}

