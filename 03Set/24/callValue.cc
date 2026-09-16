#include "main.ih"

//passes value to fun 10000000 times
void callValue(string const &prog)
{
    for (size_t idx = 0; idx < 10000000; ++idx)
        fun(prog);
}
