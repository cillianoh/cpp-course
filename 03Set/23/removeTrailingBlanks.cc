#include "main.ih"

//remove trailing blanks in string
void removeTrailingBlanks(string &nextLine)
{  
                                            //remove the trailing blanks and
                                            //update string
    nextLine = nextLine.substr(0, nextLine.find_last_not_of(" \t\r") + 1); 
}
