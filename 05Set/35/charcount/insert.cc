#include "charcount.ih"

void CharInfo::insert(char ch)
{
                                    // create a temp list with 1 more element
    Char *tempList = new Char[d_nCharObj + 1];

                                    // for each element in the list,
                                    // if it is before insert loc. dont change
                                    // add ch at d_charLoc,
                                    // fill the rest of the list with old el.
    for (size_t indx = 0; indx != d_nCharObj + 1; ++indx)
        tempList[indx] = indx < d_charLoc ? d_list[indx] 
                         : indx == d_charLoc ? Char(ch) 
                         : d_list[indx - 1];
                                  
    delete[] d_list;                // delete old list
    d_list = tempList;              // reassign

    ++d_nCharObj;                   // update number of objects in list
}
