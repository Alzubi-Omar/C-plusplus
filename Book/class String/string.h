/*If you use == to test strings for equality, you will not get the result you expect.
The reason for these problems is that strings are implemented as arrays rather than simple values.
*/

// FILE: mystring.h
// CLASS PROVIDED: string (a simple version of the Standard Library string class)
//
// CONSTRUCTOR for the my_string class:
//   string(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
// CONSTANT MEMBER FUNCTIONS for the my_string class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the
//     string.
//
//   char operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
// MODIFICATION MEMBER FUNCTIONS for the my_string class:
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the string.
//
//   void reserve(size_t n)
//     Postcondition: All functions will now work efficiently (without
//     allocating new memory) until n characters are in the string.
//
//   void insert(size_t n)
//     Postcondition: A hyphen is added to a string at position n or n+1
//     depending on where n is in a string.
//
//   void operator =(const my_string& source)
//     Postcondition: The string has been set to be equal to source.
//
// NON-MEMBER FUNCTIONS for the my_string class:
//   string operator +(const string& s1, const string& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   istream& operator >>(istream& ins, string& target)
//     Postcondition: A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the string has not
//     been read.
//
//   ostream& operator <<(ostream& outs, const string& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//   void getline(istream& ins, string& target)
//     Postcondition: A string has been read from the istream ins. The reading
//     operation starts by skipping any white space, then reading all characters
//     (skipping any additional whitespace, leaves only one space between
//     words) until the newline character is read and discarded (but not
//     added to the end of the string). The return value is ins.
//
//  VALUE SEMANTICS for the my_string class:
//    Assignments and the copy constructor may be used with string objects.
//
//  TOTAL ORDER SEMANTICS for the string class:
//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
//    for the string class, forming a total order semantics, using the usual
//    lexicographic order on strings.
//
// DYNAMIC MEMORY usage by the string class:
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, resize, operator +=, operator +, and the
//   assignment operator.

#ifndef MYSTRING_H
#define MYSTRING_H
#include <cstdlib> // Provides size_t

namespace STRING_CLASS
{
    class my_string
    {
    public:
        // CONSTRUCTORS and DESTRUCTOR
        my_string(const char str[ ] = "");
        my_string(const my_string& source);
        ~my_string();
        // MODIFICATION MEMBER FUNCTIONS
        void operator +=(const my_string& addend);
        void operator +=(const char addend[ ]);
        void operator +=(char addend);
        void reserve(size_t n);
        void operator =(const my_string& source);
        void insert(size_t n);
        // CONSTANT MEMBER FUNCTIONS
        size_t length() const {return current_length; }
        char operator [ ](size_t position) const;
        // FRIEND FUNCTIONS
        friend std::ostream& operator <<(std::ostream& out, const my_string& source);
        friend bool operator ==(const my_string& s1, const my_string& s2);
        friend bool operator !=(const my_string& s1, const my_string& s2);
        friend bool operator >=(const my_string& s1, const my_string& s2);
        friend bool operator <=(const my_string& s1, const my_string& s2);
        friend bool operator > (const my_string& s1, const my_string& s2);
        friend bool operator < (const my_string& s1, const my_string& s2);
    private:
        char * sequence; //The string is stored as a null-terminated string in the dynamic array that sequence points to.
        size_t allocated; //total length of the dynamic array
        size_t current_length; // total number of characters prior to the null character
    };

    // NON-MEMBER FUNCTIONS for the string class
    my_string operator +(const my_string& s1, const my_string& s2);
    std::istream& operator >>(std::istream& ins, my_string& target);
    void get_line(std::istream& ins, my_string& target);
    void eat_white(std::istream& ins, my_string& target);
}

#endif //MYSTRING_H
