#include "main.ih"

//get text from istream and remove all duplicate arguements line by line
string fixText(string argString)
{
    string text{};
    getline(cin, text, '\0');             //get text from istream
    
                                        
    string alteredText = "";
    string nextLine = "";
    for (char const el : text)
    {
        nextLine += el;
            if (el == '\n' || el == '\0')       //if new line or EOF
            {
                removeTrailingBlanks(nextLine); //removes trailing whitespace
                for (char const el : argString) //for each arg char in the string
                    removeChars(nextLine, el);  //check for duplicates and remove
                alteredText += nextLine;        //add line to the altered text
                nextLine = "";                  //reset next line
            }
    }
    return alteredText;
}
