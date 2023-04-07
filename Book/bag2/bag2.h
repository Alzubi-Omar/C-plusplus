//Four Rules
//When a class uses dynamic memory, you will generally follow these four rules:
//1. Some of the member variables of the class are pointers.

//2. Member functions allocate and release dynamic memory as needed.

//3. The automatic value semantics of the class is overridden (otherwise two
//different objects end up with pointers to the same dynamic memory). This
//means that the implementor must write an assignment operator and a copy
//constructor for the class.

//4. The class has a destructor. The primary purpose of the destructor is to
//return all dynamic memory to the heap.


/*
When a member variable of a class is a pointer to dynamic memory, the class
should always be given a destructor, and the value semantics should always be
defined (that is, a copy constructor and an overloaded assignment operator should
be provided).
• The destructor is responsible for returning an object’s dynamic memory to
the heap. If you forget the destructor, then dynamic memory that is allocated
to the object will continue to occupy heap memory, even when the object is
no longer needed.
• The copy constructor and the overloaded assignment operator are responsible
for correctly copying one object to another. Make sure that the copying
process allocates new memory for the new copy, rather than just copying the
pointers from one object to another. If you forget the copy constructor, then
value parameters and return values from functions will perform incorrectly.
*/

// FILE: bag2.h
// CLASS PROVIDED: bag (a container class for a collection of items)
//
// TYPEDEFS and MEMBER CONSTANTS for the bag class:
//   typedef _____ value_type
//     bag::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef _____ size_type
//     bag::size_type is the data type of any variable that keeps track of how
//     many items are in a bag.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     bag::DEFAULT_CAPACITY is the initial capacity of a bag that is created
//     by the default constructor.
//
// CONSTRUCTOR for the bag class:
//   bag(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bag is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
//  bag::bag(const bag& source)
//  Postcondition: The bag that is being constructed has been initialized
//  with the same items and capacity as source.
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//     
//     void reserve(size_type new_capacity)
//     Postcondition: The bag's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bag). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
//     size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//     bool erase_one(const value_type& target)
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//     void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//     void operator +=(const bag& addend) 
//     Postcondition: Each item in addend has been added to this bag.
//
//  void bag::operator =(const bag& source);
//     Postcondition: The bag that activated this function has the same items
//     and capacity as source.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   size_type size( ) const 
//     Postcondition: Return value is the total number of items in the bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bag
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//   Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, reserve, insert, operator += ,
//   operator +, and the assignment operator.

#ifndef MAIN_SAVITCH_BAG2_H
#define MAIN_SAVITCH_BAG2_H
#include <cstdlib> // Provides size_t

namespace BAG_2 
{
    class Bag
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30;
        // CONSTRUCTORS and DESTRUCTOR
        Bag(size_type initial_capacity = DEFAULT_CAPACITY);
        Bag(const Bag& source);
        ~Bag();
        // MODIFICATION MEMBER FUNCTIONS
        void reserve(size_type new_capacity);
        bool erase_one(const value_type& target);
        size_type erase(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const Bag& addend);
        void operator -=(const Bag& diffend);
        void operator =(const Bag& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const {return used;}
        size_type count(const value_type& target) const;
    private:
        value_type * data; // Pointer to partially filled dynamic array
        size_type used; // How much of array is being used
        size_type capacity; // Current capacity of the bag
    };
    // NONMEMBER FUNCTIONS for the bag class
    Bag operator +(const Bag& b1, const Bag& b2 );
    //Bag operator -(const Bag& b1, const Bag& b2);
}
#endif
