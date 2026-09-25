#include "student.ih"

istream &Student::nextLine(istream &in, string &line)
{
    if (getline(in, line))
        ++s_lineNr;

    if (d_verbose)
        d_results << "verbose: nextline " << s_lineNr << line << '\n';
 
    return in;   
}
