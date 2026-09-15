#include "main.ih"

//unencrypt a string which was encrypted using the ceasar cipher and return it
string deCaesar(string encrypted)
{
    string unencrypted = "";

    for (const char &el: encrypted)      //for each char in the encrypted string
    {
        if (isalpha(el))                 //if its a letter decrypt it
        {
            char lcel = tolower(el);     //change to lower case

            if (lcel - 3 < 'a')          //if it goes below letters
                                         //subtract how far it goes below from z
                unencrypted += ('z' + lcel - 'c');
            else                         //if not just go down 3 places
                unencrypted += (lcel - 3);
        }
        else                             //if its not a letter don't change it
            unencrypted += el;
    }

    return unencrypted;                  //return unencrypted string
}
