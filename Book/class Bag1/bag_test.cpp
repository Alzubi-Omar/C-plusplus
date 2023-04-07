#include "bag2.h"       // With Item defined as an int
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS

using namespace std;
using namespace BAG_2;

void get_ages(Bag& ages)
{
    int user_input; // An age from the user's family
    cout <<  "Type the ages in your family. " << endl;
    cin>> user_input;
    while (user_input >=0)
    {
        ages.insert(user_input);
        cin >> user_input;
    }    
}

void check_ages(Bag& ages)
{
    int user_input; // An age from the user's family
    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size() > 0)
    {
        cin >> user_input;
        if(ages.erase_one(user_input))
            cout << "Yes, I've got that age and have removed it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}


int main()
{
    Bag ages;

    get_ages(ages);
    check_ages(ages);
    cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;
}
