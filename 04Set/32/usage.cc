#include "main.ih" 

// C++ 2018-2019 rating procedure: 3 std = 60%,
// all std = 70%, each optional = 20%, max total: 100%

// with -r: if the max. percentage < 100 % (e.g, only 4 basic exercises, so
// max percentage would be 70%, then multiply the set's percentage by such a
// factor that the all-correct percentage becomes 100.

void usage(string const &base)
{
                                                // copyright message 
    std::cout <<  base << " Version " << version << " by " << author << "\n" 
"Copyright (c) " << year << " (GPL).\n"
"\n"
"Usage: " << base << R"( [options] studentfile
Where: 
    options: 
     -f (--no-light-weight): only display the full-sized course results
         omitting light-weight variants
     -h (--help): display this usage info
     -r (--reduced-set): sets with small numbers of exercises are rated 100%
         if all exercises are rated 1.
     -v (--version): display version number and end the program
     -V (--verbose): write lines read from students file + line numbers to
            cout before the results. After reading all student file lines 
            the line 'End Of File' is written.

    studentfile: file containing student records, organized as follows: 
                    Name of the student
                     ... (extra lines)
                     answer vector
                 answers: 0, 1, ?, or . (= not answered)
       A student record with a 2nd line equal to 'group' defines a group
       of students. 
       Their ratings are added to the individual student's ratings, which
       must be available in the full student records
       A student record with a 2nd line equal to 'attendee' defines an
       attendee, who's not showing up in the report listings

    studentfile.vec: a file by the name <studentfile>.vec must contain two
                     lines: 
      1st line:   <nr>    - deadline: number of exercises
                     which must have been completed.
                     i.e., the number of the last item
                           for which the deadline is set
                 <s1 s2 ... sn> - last itemnrs per series (increasing)
                 prefix set itemnrs by - to indicate that a set is
                 completely ignored.
      2nd line:     vector of answer indicators:
                        .   standard question
                        +   advanced question
                     space characters: question is ignored

    Results are written to the file 'results'
    An updated studentfile is written on <studentfile>.new

    The program (git/)cursist/ids is used to assign IDs and to change 
    e-mail addresses so only lowercase characters are used

)";
}






