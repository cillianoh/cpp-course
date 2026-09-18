#include "main.ih"

//inserts a subject at a specific place in list
void insertSubject(size_t *line, size_t place, size_t nSubjects)
{
    size_t tempLine[nSubjects]{};

                                                  //for full array
    for (size_t indx = 0; indx != nSubjects; ++indx)
    {
                                                  //don't change before
                                                  //insertion place, add new
                                                  //subject at place and fill
                                                  //the rest with old els
        tempLine[indx] = indx < place ? line[indx]
                         : indx == place ? newSubject()
                         : line[indx - 1];
    }
                                                  //update the original list
    for (size_t indx = 0; indx != nSubjects; ++indx)
       line[indx] = tempLine[indx]; 
}
