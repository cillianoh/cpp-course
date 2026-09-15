#include "main.ih"

//inserts a subject at a specific place in list
void insertSubject(size_t (&line)[maxLine], size_t place)
{
    size_t tempLine[maxLine]{};

    for (size_t indx = 0; indx != maxLine; ++indx)  //for full array
    {
        if (indx < place)                           //don't change elemenets 
                                                    //before insertion place
            tempLine[indx] = line[indx];
        else if (indx == place)                     //at insertion place generate
                                                    //a new subject
            tempLine[indx] = newSubject();
        else                                        //fill the rest with old els
            tempLine[indx] = line[indx - 1];
    }

    for (size_t indx = 0; indx != maxLine; ++indx)  //update the original list
       line[indx] = tempLine[indx]; 
}
