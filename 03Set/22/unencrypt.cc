#include "main.ih"

//output unencrypted text from an encrypted txt file
void unencrypt()
{
    string encrypted;
    getline(cin, encrypted, '\0');          //extract encrypted text from istream
                                            
                                            //unencrypt
    string unencrypted = deCaesar(encrypted);
    cout << unencrypted;                    //output
}
