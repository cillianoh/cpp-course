#include "students.ih"

void Students::computeScores()
{
    for (Student &student: d_student)
    {
        if (student.isParticipant())
            student.computeScores();
    }
}
