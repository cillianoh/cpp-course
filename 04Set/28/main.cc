#include "main.ih"

int main(int argc, char **argv)
{
    Line line;                       // declare object
    line.getLine();                  // get the next line
    cout << line.next();             // output next substring without " \t"
}
