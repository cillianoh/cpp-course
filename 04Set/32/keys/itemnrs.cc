#include "keys.ih"

    // first line of students.vec

void Keys::itemNrs(istream &studVec)
{
    string line;
                                        // deadline nr and accumulated nrs of
    if (!getline(studVec, line))        // items/set 
        fmsg << d_vecName << ": missing item-nr vectors" << noid;

    istringstream in(line);

    int nItems;

    in >> d_nDeadline >> nItems;        // get the #deadlined items, and 
                                        // # items in the 1st set

    bool validDeadline = d_nDeadline == 0;

    if (not in)
        fmsg << d_vecName << 
                ": missing deadline and #items in the 1st set" << noid;

    updateSets(nItems);

    while (true)                        // fill the # items / set vector
    {
        validDeadline |= d_nDeadline == abs(nItems);

        if (not (in >> nItems))         // all setnrs were read
            break;

        if (abs(nItems) <= d_nSet.back())
            fmsg << d_vecName << ": #items per set (" << abs(nItems) << ") "
                    " not increasing after " << d_nSet.back() << noid;

        updateSets(nItems);
    }

    if (not validDeadline)
        fmsg << "deadline item nr. (" << d_nDeadline << ") not at a "
                " set boundary" << noid;

    d_nStd.resize(d_nSet.size());
    d_nAdv.resize(d_nSet.size());
}







