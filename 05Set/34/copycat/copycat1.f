extern char **environ;

inline CopyCat::CopyCat()
:
    CopyCat(environ)                // intialise with environ variables
{}
