#include "student.ih"

void Student::readStudentRecord(istream &in, string &line)
{
    if (line != ".")            // line must be '.' line
        fmsg << "Missing record at line " << s_lineNr << noid;

    s_recordLineNr = s_lineNr;

    size_t pos;
    size_t nLines = 0;

    d_isGroup = false;
    d_attendee = false;

    in >> d_id;                 // get the student ID
    while 
    (
        nextLine(in, line)      // the student's name
        &&                      // containing non-blank characters:
        (pos = line.find_last_not_of(" \t")) != string::npos
    )
    {
        ++nLines;
        d_isGroup |=    line.find("group") == 0;
        d_attendee |=   line.find("attendee") == 0;
        d_record.push_back(line.substr(0, pos + 1));    // add all lines

        if (line.find("email:") == 0)                   // the e-mail entry
            setEmail(line);                             // must have an addr.
    }

    if (nLines < 3)
        fmsg << "Invalid data in record starting at line " << 
                                                    s_recordLineNr << noid;

    if (d_verbose)
        d_results << "verbose: End Of File\n";

    in.clear();
}


