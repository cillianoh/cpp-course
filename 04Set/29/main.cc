#include "main.ih"

int main(int argc, char **argv)
{
    Parser parser;

    while (parser.reset())           // read until one has no non-ws chars
    {
        double value;
        Parser::Return ret;

                                     // while not end of line
        while ((ret = parser.number(&value)) != Parser::EOLN)
        {
                                    // if ret is a number display
            if (ret == Parser::NUMBER)
                cout << value
                     << (parser.isIntegral() ? " (integral)" : " (real)")
                     << '\n';
            else
                cout << "not a number\n";
        }       
    } 
}
