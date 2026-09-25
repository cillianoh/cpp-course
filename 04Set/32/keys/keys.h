#ifndef INCLUDED_KEYS_
#define INCLUDED_KEYS_

#include <iosfwd>
#include <vector>
#include <string>

class Keys
{
    friend std::ostream &operator<<(std::ostream &out, Keys const &keys);

    std::string d_vecName;

    std::string d_key;                  // question indicators

    std::vector<bool>   d_useSet;       // true: the set is used
    std::vector<size_t> d_nSet;         // # questions per set
    std::vector<size_t> d_nStd;         // # std questions per set
    std::vector<size_t> d_nAdv;         // # adv. questions per set

    size_t d_nDeadline;                 // # deadline items
    size_t d_nDeadlineSets = 0;         // # deadlined sets

    size_t d_nIgnored = 0;              // # ignored
    size_t d_nItems;                    // # in use (= key length - nIgnored)
    size_t d_nUnusedSets = 0;
    size_t d_nUnusedDeadlineSets = 0;

    public:
        Keys();

        void read();

        size_t nSets() const;                   // number of sets
        size_t nUnusedSets() const;             // number of unused sets
        size_t nVec() const;                    // #items in students.vec
        size_t nItems() const;                  // total number of used items
        size_t nKeys() const;                   // # available keys
        size_t nIgnored() const;                // number of ignored items
        bool   used(size_t setIndex) const;     // true: set is used
        size_t nSet(size_t setIndex) const;     // # questions in set setIdx    
        size_t nStd(size_t setIndex) const;     // # std q. in set setIdx
        size_t nAdv(size_t setIndex) const;     // # adv. q. in set setIdx
        size_t maxGrade(size_t setIndex) const; // the max. grade of a set
                                                // (<= 10)
        size_t nDeadline() const;               // # items at the deadline
        size_t nDeadlineSets() const;           // # deadlined sets     
                                                // only valid if nDeadline
                                                // != 0
        size_t nUnusedDeadlineSets() const;

        bool ignore(size_t index) const;        // . key
        bool advanced(size_t index) const;      // d_advanced[idx] == 1

        char operator[](size_t index) const;    // d_key[index] == 1

    private:
        void answers(std::istream &studVec);
        std::ostream &insert(std::ostream &out) const;

        void itemNrs(std::istream &studVec);    // 1st line of students.vec
        void setNdeadlineSets();
        void typeCount();                       // 2nd line of students.vec
        void updateSets(int nItems);

};

inline std::ostream &operator<<(std::ostream &out, Keys const &keys)
{
    return keys.insert(out);
}

inline size_t Keys::nSets() const
{
    return d_nSet.size();
}

inline size_t Keys::nKeys() const
{
    return d_nSet.back();
}

inline size_t Keys::nUnusedSets() const
{
    return d_nUnusedSets;
}

inline size_t Keys::nUnusedDeadlineSets() const
{
    return d_nUnusedDeadlineSets;
}

inline size_t Keys::nItems() const
{
    return d_nItems;
}
        
inline size_t Keys::nVec() const
{
    return d_key.length();
}
        
inline size_t Keys::nIgnored() const
{
    return d_nIgnored;
}
        
inline bool Keys::ignore(size_t index) const
{
    return d_key[index] == ' ';
}

inline bool Keys::advanced(size_t index) const
{
    return d_key[index] == '+';
}

inline size_t Keys::nDeadline() const
{
    return d_nDeadline;
}

inline size_t Keys::nDeadlineSets() const
{
    return d_nDeadlineSets;
}

inline char Keys::operator[](size_t index) const
{
    return d_key[index];
}

inline size_t Keys::nSet(size_t idx) const
{
    return d_nSet[idx]; 
}

inline size_t Keys::nStd(size_t idx) const
{
    return d_nStd[idx]; 
}

inline size_t Keys::nAdv(size_t idx) const
{
    return d_nAdv[idx]; 
}

inline bool Keys::used(size_t index) const
{
    return d_useSet[index];
}

//inline size_t Keys::maxStd(size_t idx) const
//{
//    return d_maxStd[idx]; 
//}
//
//inline size_t Keys::maxAdv(size_t idx) const
//{
//    return d_maxAdv[idx]; 
//}

#endif


