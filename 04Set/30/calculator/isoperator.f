inline bool isOperator(string const &op)
{   
                                    // true if string contains operator and
                                    // only one char
    return op.length() == 1 && 
            op.find_first_of("+-/*%") != string::npos;

}
