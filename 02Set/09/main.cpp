#include <iostream>
#include <string>
using namespace std;

// counts and displays the number of a-, e-, and i-characters in a 
// text file, which was redirected into the input stream
int main()
{
  
    string text;                      
    getline(cin, text, '\0');          // extract text from cin, until EOF
    
    int na = 0;                        // initialise letter counters
    int ne = 0;
    int ni = 0;

    for (const char& el : text)        // RBFL to test each character in text
    {                                  // test each character seperatly
        switch (el)                    // and tally
        {                           
            case 'a': case 'A':        
                na += 1;   
                break;
            case 'e': case 'E': 
                ne += 1; 
                break;
            case 'i': case 'I':
                ni += 1; 
                break;
            default: break;
        }
    }

    cout << "# a-chars: " << na        // output results
         << ", # e-chars: " << ne
         << ", # i-chars: " << ni << '\n';

}