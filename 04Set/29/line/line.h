#ifndef INCLUDED_LINE_
#define INCLUDED_LINE_
#include <string>

class Line
{
    std::string d_line;                // next line 
    size_t d_pos = std::string::npos;  // start of next substring

    public:
        bool getLine();                // true if line has no ws chars
        std::string next();            // next non-ws substring, or ""
};
        
#endif
