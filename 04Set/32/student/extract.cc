#include "student.ih"

istream &Student::extract(istream &in)
{
    string line = skipLines(in);    // skip empty/ws lines and = lines

    if (!in)
        return in;

    readStudentRecord(in, line);

    size_t nKeys = d_keys.nKeys();
                                        // record is the full student record
    if (d_record.back().size() < nKeys)      // not enough answers?
        d_record.back().resize(nKeys, '.');  // extend
    else if (d_record.back().size() > nKeys)
        d_record.back().resize(nKeys);

    return in;
}






