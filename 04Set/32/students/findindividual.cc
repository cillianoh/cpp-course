#include "students.ih"

Students::iterator 
    Students::findIndividual(string const &names, iterator begin) 
{
    return find_if(begin, d_student.end(), 
        [&](Student const &student)
        {
           return  
                not student.isGroup() 
                && 
                names.find(student.name()) != string::npos;
        }
    );
}
