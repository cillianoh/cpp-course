#include "main.ih"

//passes a reference to fun 2 10000000 times
void callRef(string const &prog)
{
    for (size_t idx = 0; idx < 10000000; ++idx)
        fun2(prog);
}
