#include "charcount.ih"

void CharInfo::append(char ch)
{
                                    // create a new list that is 1 longer
    Char *tempList = new Char[d_nCharObj + 1];

                                    // copy the old list to the temp one
    for (size_t indx = 0; indx != d_nCharObj; ++indx)
        tempList[indx] = d_list[indx];
            
                                    // add a new char object to the end
    tempList[d_nCharObj] = Char(ch); 
    
    delete[] d_list;                // delete the old list
    d_list = tempList;              // reasign

    ++d_nCharObj;                   // update number of objects in list
}
