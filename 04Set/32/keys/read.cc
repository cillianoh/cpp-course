#include "keys.ih"

// Example:
//    0      8
//    ...++...      .: stdandard, +: advanced, blank: ignore


void Keys::read()
{
    ifstream studVec;

    Exception::open(studVec, d_vecName);

    itemNrs(studVec);                   // read the last question nrs per set
                                        // (1st line)

    answers(studVec);                   // read the answer vector (2nd line)

    typeCount();                        // count # std and advanced per set

    setNdeadlineSets();                 // determine # of deadlined sets

//    if (Arg::instance().option('V'))
//        cout << *this << '\n';
}





