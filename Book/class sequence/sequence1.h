// FILE: sequence1.h

// VALUE SEMANTICS for the sequence class:
// Assignments and the copy constructor may be used with sequence objects.

#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib> // Provides size_t

namespace SEQUENCE_H
{

    class Sequence 
    {
    public:
        // TYPEDEF and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

        // CONSTRUCTOR
        Sequence(); //Postcondition: The sequence has been initialized as an empty sequence.

        //MODIFICATION MEMBER FUNCTIONS for the sequence class:
        void start();
        //Postcondition: The first item in the sequence becomes the current item (but if the
        // sequence is empty, then there is no current item).

        void advance();
        // Precondition: is_item returns true.
        // Postcondition: If the current item was already the last item in the sequence, then there
        // is no longer any current item. Otherwise, the new item is the item immediately after
        // the original current item.

        void insert(const value_type& entry);
        // Precondition: size( ) < CAPACITY.
        // Postcondition: A new copy of entry has been inserted in the sequence before the
        // current item. If there was no current item, then the new entry has been inserted at the
        // front. In either case, the new item is now the current item of the sequence.

        void attach(const value_type& entry);
        // Precondition: size( ) < CAPACITY.
        // Postcondition: A new copy of entry has been inserted in the sequence after the current
        // item. If there was no current item, then the new entry has been attached to the end of
        // the sequence. In either case, the new item is now the current item of the sequence.

        void remove_current();
        // Precondition: is_item returns true.
        // Postcondition: The current item has been removed from the sequence, and the
        // item after this (if there is one) is now the new current item.

        // CONSTANT MEMBER FUNCTIONS
        size_type size() const;
        // Postcondition: The return value is the number of items in the sequence.

        bool is_item() const;
        // Postcondition: A true return value indicates that there is a valid “current” item that
        // may be retrieved by the current member function (listed below). A false return value
        // indicates that there is no valid current item.

        value_type current() const;
        // Precondition: is_item( ) returns true.
        // Postcondition: The item returned is the current item in the sequence.

    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
}
#endif
