#include "students.ih"

void Students::read()
{
    ifstream in;
    Exception::open(in, d_studFileName);

    while (true)
    {
        Student student{ d_keys, d_verbose, d_results };

        if (not (in >> student))
            break;

        d_student.push_back(move(student));
        d_nStudents += not student.isGroup();
        d_nAttendees += student.isAttendee();
    }

    d_nStudents -= d_nAttendees;
}
