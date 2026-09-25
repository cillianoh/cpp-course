#include "student.ih"

void Student::setEmail(string const &line)
{
    try
    {
        size_t pos = line.find_first_of(" \t");
        if (pos == string::npos)
            throw false;

        d_email = String::lc(String::trim(line.substr(pos)));
        if (d_email.empty())
            throw false;
    }
    catch (bool)
    {
        fmsg << "Line " << s_lineNr << ": format error in " << line << noid;
    }        
}


