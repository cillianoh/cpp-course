#include "charcount.ih"

void CharInfo::add(char ch)
{
    if (d_nCharObj == 0)            // if no objects in list
    {
        append(ch);                 // add char to end and return
        return;
    }

    switch (locate(ch))             // check what needs to be done to the char
    {
        case APPEND:               
            append(ch);             // add char to the end of the list
        break;
        case INSERT:
            insert(ch);             // insert char at d_charLoc
        break;
        case INC:
                                    // increase the frequence field of the given
                                    // char if already included in list
            ++d_list[d_charLoc].d_freq;
        break;
        default:
        break;
    }
}
