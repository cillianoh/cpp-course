#include "main.ih"

ReturnValues combine(int argc, char **argv)
{
    ReturnValues returnValues;                        //define struct

    int indx = atoi(argv[1]);                         //requested arg index

                                                      //if indx is positive and
                                                      //less then max arguement
                                                      //indexs, then true
    returnValues.ok = indx > 1 && indx - 1 <= argc ? true : false;
    
    if (returnValues.ok)                              //if requested arg exists
    {
        returnValues.nr = static_cast<size_t> (indx); //arg no. is indx
        returnValues.value = string(argv[indx - 1]);  //arg value is set
    }
    else
        returnValues.value = "";                      //if requested arg doesnt
                                                      //exist, value is blank

    return returnValues;                              //return struct
}
