#include "keys.ih"

void Keys::answers(istream &studVec)
{
    if (!getline(studVec, d_key))           // answer vector
        fmsg << d_vecName << ": missing answer vector" << noid;

                                            // trim final blanks
    if (size_t pos = d_key.find_last_not_of(" \t"); pos != string::npos)
        d_key.erase(pos + 1);

    if (d_key.size() > d_nSet.back())
        fmsg << d_vecName << ": answer vector contains more than " << 
                d_nSet.back() << " question indicators" << noid;

    if (size_t pos = d_key.find_first_not_of(" .+"); pos != string::npos)
        fmsg << d_vecName << ": invalid item indicator `" << d_key[pos] <<
                "' at offset " << pos << noid;
        
    d_key.resize(d_nSet.back(), ' ');           // initialize to 'ignore'
}
