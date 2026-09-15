#include <iostream>
#include <string>
using namespace std;

// Extract the netmask from a given ip4 adress, assuming the first
// four arguments have values between 0 and 255 and the fifth
// arguement has a value between 0 and 32
int main (int argc, char *argv[])
{

    size_t ip4 = (stoul(argv[1])                      // Compute octet 1
                 << 24 | stoul(argv[2])               // Compute octet 2
                 << 16 | stoul(argv[3])               // Compute octet 3
                 << 8 | stoul(argv[4]))               // Compute octet 4
                 & (~0UL << (32 - stoul(argv[5])));   // Mask the network bits

    cout << ((ip4 >> 24) & 0xFF) << '.'               // Print masked adress
         << ((ip4 >> 16) & 0xFF) << '.'
         << ((ip4 >> 8) & 0xFF) << '.'
         << (ip4 & 0xFF);

}
