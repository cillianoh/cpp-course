#include <iostream>

char example[] = R"R(^\s+Encryption key:(\w+)
^\s+Quality=(\d+)
^\s+E?SSID:"([[:print:]]+)"
^\s+ssid="([[:print:]]+)"
)R";                             //RSL found from example output

int main()
{
    std::cout << example;        //RSL inserted to cout to be printed
}