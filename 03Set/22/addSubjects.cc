#include "main.ih"

//add a number of subjects passed as an arguement to a list
void addSubjects(size_t *line, size_t nSubjects)
{
                                        //for no. of subjects entering
    for (size_t indx = 0; indx != nSubjects; ++indx)
    {                                   
                                        //for no. of spaces in line
        for (size_t indx = 0; indx != nSubjects; ++indx)
        {
                                        //if subject has blue eyes or no 
                                        //subject there
            if (line[indx] == 1 || line[indx] == 0)              
            {                           
                                        //insert subject and leave loop
                insertSubject(line, indx, nSubjects);
                break;
            }
        }
    }
}
