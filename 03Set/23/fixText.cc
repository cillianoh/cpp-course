#include "main.ih"

//get text from istream and remove all duplicate arguements line by line
string fixText(string argString)
{
    string alteredText;
    string nextLine;
    while (getline(cin, nextLine))
    {
        removeTrailingBlanks(nextLine); //removes trailing whitespace

        for (char const el : argString) //for each arg char in the string
            removeChars(nextLine, el);  //check for duplicates and remove
                                            
        alteredText += nextLine;        //add line to the altered text
        alteredText += '\n';            //getline removes '\n' so need to readd
    }

    return alteredText;
}
