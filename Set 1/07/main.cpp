#include <iostream>
#include <string>
using namespace std;

// outputs "hello xxx", where xxx is a specified command line arguement,
// default = hello world, assumes 2 argument when no. of arguments > 2 is int
int main(int argc, char *argv[])
{

    cout << "hello " << (argc == 2 ? argv[1] :   // if two arguments, second 
        (argc > 2 ? argv[stoul(argv[1])] :       // is used. if >2, second is
             "world"));                          // index for arguement. else
                                                 // "world" is concacatenated
}