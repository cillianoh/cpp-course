#include "students.ih"

void Students::results() const
{
    header();                           // info up to the record of the 1st
                                        // student

    d_results.setf(ios::fixed, ios::floatfield);

    size_t noExercises = 0;
    size_t okCount = 0;

    vector<Student const *> sorter( d_student.size() );

    for (size_t idx = 0; idx != d_student.size(); ++idx)
        sorter[idx] = &d_student[idx];

    for (Student const *student: sorter)
    {
        if (student->isParticipant())       // show results of the individual
            student->results(&noExercises, &okCount,         // students
                             d_lightweight, d_reducedSet);    
    }

    d_results.precision(0);

    d_results <<
        "=================================================================\n";

    showNoOfExercises(noExercises);
    showDeadlineInfo(noExercises, okCount);

    d_results.close();
}

