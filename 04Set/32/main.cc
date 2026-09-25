#include "main.ih"           // program header file

namespace 
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption("help", 'h'),
        Arg::LongOption("no-light-weight", 'f'),
        Arg::LongOption("reduced-set", 'r'),
        Arg::LongOption("version", 'v'),
        Arg::LongOption("verbose", 'V'),
    };

    Arg::LongOption const *const longEnd = longOptions + size(longOptions);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hfrvV",
                               longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, version, 1);
        
    Keys keys;
    keys.read();

    Students students(keys, "results");

    students.read();
    students.mergeGroups();                 // merge group ratings to 
                                            // individual ratings

                                            // calls student computeScores
    students.computeScores();               // for each Student

    students.results();                     // writes mail, ID, name

//    students.results("results.all", true);  // true: ID + name

    students.write();
}
catch (exception const &err)
{
    cout << err.what() << '\n';
    return 1;
}
catch (int x)
{
    return x;
}
