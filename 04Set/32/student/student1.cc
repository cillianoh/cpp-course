#include "student.ih"

Student::Student(Keys const &keys, bool verbose, std::ostream &results)
:
    d_keys(keys),
    d_verbose(verbose),
    d_stdSum(d_keys.nSets()),
    d_advSum(d_keys.nSets()),
    d_results(results)
{}
