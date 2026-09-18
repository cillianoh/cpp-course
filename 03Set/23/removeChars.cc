#include "main.ih"

//remove double chars of arg and update the string
void removeChars(string &nextLine, char arg)
{
    string tempLine;

    char lastEl = 0;
    for (char const el : nextLine)   //for all the els in the next line
    {
       if (lastEl != el || el != arg)//if the last el is different to the next
           tempLine += el;           //add it to the temporary line
  
       lastEl = el;                  //update the last element 
    }

    nextLine = tempLine;             //update original line with new one 
}
