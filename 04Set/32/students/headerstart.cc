#include "students.ih"
#include "../VERSION"

void Students::headerStart() const
{
    d_results << 
        "Cursist V" VERSION ". " << DateTime{ DateTime::LOCALTIME } << "\n"
        "\n"
        "Number of participants: " << d_nStudents << '\n';
    
    if (d_nAttendees)
        d_results << "Number of attendees: " << d_nAttendees << '\n';

    d_results <<
        "\n"
        "Deadline: exercise " << d_keys.nDeadline() << 
                            " (shown as D in the exercise numbers listing)\n"
        "          exercises 1 through D cannot be submitted anymore.\n"
        "Total number of basic and advanced exercises: " << 
                                d_keys.nItems() << '\n';

    if (d_keys.nIgnored())
        d_results << "Last-used item number in .vec: " << 
                                                    d_keys.nVec() << "\n"
                    "Total number of ignored exercises: " << 
                                                    d_keys.nIgnored() << '\n';
}

