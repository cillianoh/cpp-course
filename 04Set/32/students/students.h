#ifndef INCLUDED_STUDENTS_
#define INCLUDED_STUDENTS_

#include <fstream>
#include <string>
#include <vector>

#include "../student/student.h"

class Students
{
    Keys const &d_keys;

    std::vector<Student> d_student;
    typedef std::vector<Student>::iterator iterator;

    size_t d_nStudents = 0;
    size_t d_nAttendees = 0;

    std::string d_studFileName;

    bool d_lightweight;                     // show lightweight results
    bool d_reducedSet;                      // multiply reduced set
                                            // percentages so that all OK
                                            // becomes 100 %

    bool d_verbose;
    mutable std::ofstream d_results;

    public:
        Students(Keys const &keys, char const *file);
        
        void read();
        void mergeGroups();

        void computeScores();
        void results() const;
        void write() const;

    private:
        iterator findIndividual(std::string const &names,
                                iterator begin);

        void stdHeader() const;
        void header() const;
        void headerStart() const;

        void showNoOfExercises(size_t noExercises) const;
        void showDeadlineInfo(size_t noExercises, size_t okCount) const;
};

#endif




