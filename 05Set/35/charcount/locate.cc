#include "charcount.ih"

CharInfo::charStatus CharInfo::locate(char ch)
{
                                    // for all the objects in the list
    for (size_t indx = 0; indx != d_nCharObj; ++indx)      
    {
                                    // if ch is in a field store the indx of that
                                    // field and return include
        if (ch == d_list[indx].d_char)
        {
            d_charLoc = indx;
            return INC;
        }    
                                    // if it is not in a field store the indx of
                                    // the first char object large than it and
                                    // return insert
        if (ch < d_list[indx].d_char)
        {
            d_charLoc = indx;
            return INSERT;
        }
    } 

    return APPEND;                  // return append to add it to the end of the
                                    // list
}
