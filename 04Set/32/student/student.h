#ifndef INCLUDED_STUDENT_
#define INCLUDED_STUDENT_

#include <iosfwd>
#include <string>
#include <vector>

class Keys;

class Student
{
    friend std::istream &operator>>(std::istream &in, Student &student);

    enum Rating
    {
        NOT_ANSWERED    = '.',
        INCORRECT       = '0',
        QUESTIONABLE    = '?',
        CORRECT1        = '1',
    };

    Keys const &d_keys;

    bool d_isGroup;
    bool d_attendee;
    bool d_verbose;

    size_t d_id;                            // student ID
    std::vector<std::string> d_record;      // all record lines of this 
                                            // student
    std::string d_email;                    // e-mail address in lc chars

    static size_t s_lineNr;
    static size_t s_recordLineNr;

    std::vector<size_t> d_stdSum;           // number of OK answered std
                                            // exercises per set.

    std::vector<size_t> d_advSum;           // sum scores per item set for
                                            // advanced questions
    std::ostream &d_results;

    public:
        enum Cutoff
        {
            MINIMAL_PERCENTAGE = 56
        };

        Student(Keys const &keys, bool verbose, std::ostream &results);

        bool isGroup() const;
        bool isAttendee() const;
        bool isParticipant() const;

        std::string const &email() const;
        std::string const &name() const;
        std::string const &answers() const;
        void merge(std::string const &groupAnswers);

        std::vector<std::string>::const_iterator begin() const;
        std::vector<std::string>::const_iterator end() const;

        void computeScores();

        void results(size_t *noExercises, size_t *okCount,
                     bool lightweight, bool reducedSet) const;

        size_t id() const;

    private:
        struct Percentages
        {
            double all;
            double deadline;
        };
        void units(size_t first, size_t beyond) const;

        size_t rate(size_t setIdx, size_t itemIdx);

        void showRatings() const;

        void oddEven(size_t value) const;
        void tens(size_t first, size_t beyond) const;

        size_t answer(size_t idx) const;
        static size_t score(char answer);

        void showRating(size_t first, size_t beyond) const;

        void scoresPerSet() const;
        Percentages variants(bool lightweight, bool reducedSet) const;
        Percentages variant(size_t points, bool reducedSet) const;

        std::istream &extract(std::istream &in);

        void readStudentRecord(std::istream &in, std::string &line);
        std::istream &nextLine(std::istream &in, std::string &dest);

        std::string skipLines(std::istream &in);

        void setEmail(std::string const &line);     // assigns d_email
};

inline size_t Student::id() const
{
    return d_id;
}

inline bool Student::isGroup() const
{
    return d_isGroup;
}

inline bool Student::isParticipant() const
{
    return not d_isGroup and not d_attendee;
}

inline bool Student::isAttendee() const
{
    return d_attendee;
}

inline std::string const &Student::name() const
{
    return d_record.front();
}

inline std::string const &Student::email() const
{
    return d_email;
}

inline std::string const &Student::answers() const
{
    return d_record.back();
}

inline std::vector<std::string>::const_iterator Student::begin() const
{
    return d_record.begin();
}

inline std::vector<std::string>::const_iterator Student::end() const
{
    return d_record.end();
}


inline std::istream &operator>>(std::istream &in, Student &student)
{
    return student.extract(in);
}


#endif


