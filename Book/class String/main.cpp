#include <iostream> // Provides cout and cin
#include <cstdlib> // Provides EXIT_SUCCESS
#include "string.h" // Provides our new string class
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void match(const STRING_CLASS::my_string& variety,
            const STRING_CLASS::my_string& mine,
            const STRING_CLASS::my_string& yours);
// The two strings, mine and yours, are compared. If they are the same, then a
// message is printed saying they are the same; otherwise mine is printed
// in a message. In either case, the string variety is part of the message.

int main()
{
    const STRING_CLASS::my_string BLANK(" ");
    STRING_CLASS::my_string me_first("Demo");
    STRING_CLASS::my_string me_last("Program");
    STRING_CLASS::my_string you_first, you_last, you;

    cout << "What is your first name? ";
    cin >> you_first;
    match("first name", me_first, you_first);
    cout <<"What is your last name? ";
    cin >> you_last;
    match("last name", me_last, you_last);

    you = you_first + BLANK + you_last;
    cout << "I am happy to meet you, " << you << "." << endl;
    
    return EXIT_SUCCESS;
}

void match(const STRING_CLASS::my_string& variety,
            const STRING_CLASS::my_string& mine,
            const STRING_CLASS::my_string& yours)
            {
                if (mine == yours)
                    cout << "That is the same as my " << variety << '!' << endl;
                else
                    cout << "My " << variety << " is " << mine << '.' << endl;
            }
