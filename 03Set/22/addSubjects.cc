#include "main.ih"

//add a number of subjects passed as an arguement to a list
void addSubjects(size_t (&line)[maxLine], size_t nSubjects)
{
                                        //for no. of subjects entering
    for (size_t indx = 0; indx < nSubjects; ++indx)
    {
        size_t place = 0;
        bool subjectPlaced = false;
     
        for (size_t const &subj: line)
        {
            if (subj == 1)              //if subject has brown eyes
            {
                insertSubject(line, place);
                subjectPlaced = true;
                break;
            }
            if (subj == 1 || subj == 2) //if spot in line filled count places
                ++place;
        }

        if (subjectPlaced == false)     //if no subject placed
            insertSubject(line, place); //insert at final place
    }
}
