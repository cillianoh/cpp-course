#include <iostream>
#include <string>
using namespace std;

// remove blanks before and after a string extracted from the input stream
// output the results
int main() 
{
   string line;        
   getline(cin, line);                      //assign input stream to string

   string blanks{ ' ', '\r', '\t' };        //string containing all blank chars

                                            //substring created between indexs
   string final = line.substr(line.find_first_not_of(" \r\t"), 
                              line.find_last_not_of(" \r\t") - 
                              line.find_first_not_of(" \r\t") + 1);
                                            
   cout << '`' << final << "'\n";           //print final output
                     
}
