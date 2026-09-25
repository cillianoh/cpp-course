#include "students.ih"

Students::Students(Keys const &keys, char const *file)
:
    d_keys(keys),
    d_studFileName(Arg::instance()[0]),
    d_lightweight(not Arg::instance().option('f')),
    d_reducedSet(Arg::instance().option('r')),
    d_verbose(Arg::instance().option('V'))
{
    Exception::open(d_results, file);
    if (d_verbose)
        d_results << "verbose: writing verbose messages\n" << 
                     "verbose: key info:\n\n" << 
                     keys << "\n"
                     "verbose: end key info\n\n" ;
}
