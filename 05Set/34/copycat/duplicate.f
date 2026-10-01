inline static void CopyCat::duplicate(char **dest, char const *const *begin)
{
    *dest = ntbsCopy(*begin);        // copy NTBS to destination
} 
