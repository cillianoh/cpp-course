#ifndef INCLUDED_CHARCOUNT_
#define INCLUDED_CHARCOUNT_
#include <iosfwd>

struct Char;                        // forward declaration
struct CharInfo
{
    size_t d_nCharObj;              // no. of char objects in list
    Char *d_list;                   // pointer to list of char objects
    size_t d_charLoc;               // location of character in list
                              
    enum charStatus        
    {
        APPEND,
        INSERT,
        INC
    }; 


    CharInfo();                     // default constructor
    void add(char const ch);        // add's a char to the list of objects
                                    // locate's where a char should be in list
    charStatus locate(char const ch);  
    private: 
        void append(char const ch); // add's char to end of list
        void insert(char const ch); // inserts char at d_charLoc in list
};

struct CharCount
{

    size_t count(std::istream &in); // counts the chars in istream and add's 
                                    // them to charInfo
    CharInfo &info();               // returns a reference to charInfo
    void show(char ch);             // displays the number of times a char
                                    // appeared

    
    private:
        CharInfo charInfo;          
};

struct Char
{
    char d_char;                    // char
    size_t d_freq;                  // frequency of the char

    Char() = default;               // default constructor
    Char(char ch);                  // constructor setting d_char as ch
};

#include "charinfo.f"
#include "char.f"
#include "info.f"
       
#endif
