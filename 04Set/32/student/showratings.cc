#include "student.ih"

void Student::showRatings() const
{                   
    static size_t const blockSize = 70;

    size_t first = 0;
    size_t beyond = first + blockSize;

    string const &rating = d_record.back(); // rating vector of this student
        
    while (first < rating.size())
    {
        if (beyond > rating.size())
            beyond = rating.size();
            
        tens(first, beyond);
        units(first, beyond);
        showRating(first, beyond);
        
        first = beyond;
        beyond += blockSize;
    }
}
