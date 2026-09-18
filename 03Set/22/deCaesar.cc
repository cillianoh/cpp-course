#include "main.ih"

//unencrypt a string which was encrypted using the ceasar cipher and return it
string deCaesar(string encrypted)
{
    string unencrypted{};

    for (char const &el: encrypted)    //for each char in the encrypted string
    {
        if (!isalpha(el))              //if it's not a letter don't change it 
            unencrypted += el;

        else                           //if it is a letter decrypt it 
        {
            char lcel = tolower(el);   //change to lower case

                                       //if it goes below letters subtract how
                                       //far it goes below from z, else go down
                                       //3 spaces
            unencrypted += lcel - 3 < 'a' 
                               ? ('z' + lcel - 'c') 
                               : (lcel - 3);
        }
    }

    return unencrypted;                //return unencrypted string
}
