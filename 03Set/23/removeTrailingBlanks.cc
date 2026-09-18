#include "main.ih"

//remove trailing blanks in string
void removeTrailingBlanks(string &nextLine)
{  
                                            //remove the trailing blanks and
                                            //update string
    nextLine.resize(nextLine.find_last_not_of(" \t\r") + 1);
}
