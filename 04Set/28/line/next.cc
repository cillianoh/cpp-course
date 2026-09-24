#include "line.h"

std::string Line::next() 
{
                                     // if no more substrings
    if (d_pos == std::string::npos)
        return "";

                                     // find end of next substring
    size_t end = d_line.find_first_of(" \t", d_pos);
                                     // create substring
    std::string ret = d_line.substr(d_pos, end - d_pos);

                                     // find start of next substring
    d_pos = d_line.find_first_not_of(" \t", end);

    return ret;                      // return substring
}
