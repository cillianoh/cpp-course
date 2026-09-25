#ifndef INCLUDED_PARSER_
#define INCLUDED_PARSER_
#include "../line/line.h"

class Parser
{
    public:
        enum Return
        {
            NO_NUMBER,                // no number in substring
            NUMBER,                   // number in substring
            EOLN                      // line had no more substrings
        };

    private: 
        Line d_line;
        Return d_return;
        bool d_integral;

    public:
        bool reset();                // returns true if new line is read
        Return number(double *dest); // returns enum displaying line data

        bool isIntegral() const;     // returns true if number is integral
        std::string next();          // returns next substring

    private:
                                     // returns whether string is number or not
        Return convert(double *dest, std::string const &str);
                                     // converts string to double, returning
                                     // true if all chars converted, also sets
                                     // d_integral
        bool pureDouble(double *dest, std::string const &str);
};

#include "reset.f"
#include "isintegral.f"
#include "next.f"
        
#endif
