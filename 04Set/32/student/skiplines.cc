#include "student.ih"

string Student::skipLines(istream &in)
{
    string line;

    while (nextLine(in, line))
    {
        if (line.empty())
            continue;

        size_t pos = line.find_first_not_of(" \t");
        if (pos == string::npos)
            continue;
            
        if (line[pos] != '=')
            break;
    }

    return line;
}
