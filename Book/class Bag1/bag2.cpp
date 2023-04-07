#include "bag2.h"
#include <algorithm>
#include <cassert>

using namespace std;

namespace BAG_2 
{
    const Bag::size_type Bag::DEFAULT_CAPACITY;

    Bag::Bag(size_type initial_capacity)
    {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }

    //In the case of the copy constructor, the capacity of the dynamic array is
    //the same as the capacity of the bag that is being copied. After the dynamic array
    //has been allocated, the items may be copied into the newly allocated array,
    Bag::Bag(const Bag& source)
    {
        // Library facilities used: algorithm
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        copy(source.data, source.data + used, data); //copy(<beginning location>, <ending location>, <destination>);
    }

    Bag::~Bag()
    {
        delete [] data; //The private member variable called data points to the dynamic array.
    }

    void Bag::operator=(const Bag& source)
    {
        value_type *new_data;
        // Check for possible self-assignment:
        if(this == &source)
            return;

        if(capacity != source.capacity)
        {
            new_data = new value_type[source.capacity]; //If necessary,allocate a dynamic array of a different size.
            delete [] data; //Return the old array to the heap.
            data = new_data; //The pointer, data, now points to the newly allocated array.
            capacity = source.capacity;
        }
        used = source.used;
        copy(source.data, source.data + used, data); //Use the copy function to copy data from the source.
    }

    //reserve, which is called to explicitly increase the capacity of a bag.
    void Bag::reserve(size_type new_capacity)
    {
        // Library facilities used: algorithm
        value_type *larger_array;

        if(new_capacity == capacity)
            return;// The allocated memory is already the right size.
        
        if(new_capacity < used)
            new_capacity = used; // Canít allocate less than we are using.
        
        larger_array = new value_type[new_capacity];
        copy(data, data+used, larger_array);
        delete [] data;
        data = larger_array;
        capacity = new_capacity;
    }

    void Bag::insert(const value_type& entry)
    {
        if(used == capacity) //The first action of the insert function is to ensure that there is room for a new item.
            reserve(used + 1);
        data[used] = entry;
        used ++;
    }

    Bag::size_type Bag::erase(const value_type& target)
    {
        size_type index = 0;
        size_type many_removed = 0;
        while (index < used)
        {
            if (data[index] == target)
            {
                --used;
                data[index] = data[used];
                ++many_removed;
            }
            else
            {
                ++index;
            }
        }
        return many_removed;
    }

    bool Bag::erase_one(const value_type& target)
    {
        size_type index; // The location of target in the data array
                        // First, set index to the location of target in the data array,
                        // which could be as small as 0 or as large as used-1.
                        // If target is not in the array, then index will be set equal to used.
        index = 0;
        while ((index < used) && (data[index] != target))
            ++index;

            if(index == used)
                // target isn't in the bag, so no work to do
                return false;
            else
                // When execution reaches here, target is in the bag at data[index].
                // So, reduce used by 1 and copy the last item onto data[index].
                --used;
                data[index] = data[used];
                return true;
    }

    void Bag::operator +=(const Bag& addend)
    {
        // Library facilities used: algorithm
        if (used + addend.used > capacity)
            reserve(used + addend.used); //The += operator starts by ensuring that there is enough room for the new items.

        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;

    }

    void Bag::operator-=(const Bag& diffend)
    {
        for (int i = 0; i < diffend.used; i++)
        {
            erase_one(diffend.data[i]);
        }
    }

    Bag::size_type Bag::count(const value_type& target) const
    {
        size_type answer;
        size_type i;
        answer = 0;
        for(i = 0; i < used; ++i)
            if(target == data[i])
                ++answer;
        return answer;

    }

    Bag operator+(const Bag& b1, const Bag& b2)
    {
        Bag answer(b1.size() + b2.size()); //The function declares a bag of sufficient size

        answer += b1;
        answer +=b2;
        return answer;
    }


    /*Bag operator-(const Bag& b1, const Bag& b2)
    {
        return (b1 -= b2);
    }*/ 
    
}
