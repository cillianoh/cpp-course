#include "students.ih"

void Students::mergeGroups()
{
    auto beyond = d_student.end();

    for (Student &group: d_student)
    {
        auto single = d_student.begin();

        if (group.isGroup())
        {
            string names = group.name();

            while ((single = findIndividual(names, single)) != beyond)
            {
                single->merge(group.answers());
                ++single;
            }
        }
    }
}




