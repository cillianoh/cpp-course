#include "student.ih"

void Student::merge(std::string const &groupAnswers)
{
    auto studVect = d_record.back().begin(); // 1st answer of this student
                                            // and beyond

    for (auto group: groupAnswers)    // visit all group-answers
    {
        if (
            score(group) > score(*studVect) 
            || 
            *studVect == NOT_ANSWERED
        )
            *studVect = group;

        ++studVect;
    }
}
