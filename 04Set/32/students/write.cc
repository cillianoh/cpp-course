#include "students.ih"

void Students::write() const
{
    ifstream in;
    Exception::open(in, d_studFileName);

    ofstream out;
    Exception::open(out, d_studFileName + ".new");

    for (Student const &student: d_student)
    {
        string line;

        while (getline(in, line))
        {
            out << line << '\n';
            if (line.length() && line[0] == '.')
                break;
        }

        out << student.id();
        copy(student.begin(), student.end(), 
            ostream_iterator<string>(out, "\n"));

        while 
        (
            getline(in, line) 
            && 
            line.find_last_not_of(" \t") != string::npos
        )
            ;

        if (in)
            out << '\n';
    }
}
