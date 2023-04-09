#include "sequence.h"

#include <iostream>
#include <cassert> //allows assert

using namespace std;

namespace SEQUENCE_H
{

    const Sequence::size_type Sequence::CAPACITY;

    Sequence::Sequence()
    {
        current_index = 0;
        used = 0;
    }

    Sequence::value_type Sequence::current() const
    {
        assert(is_item());
        cout <<"CURRENT INDEX FROM CURRENT() " << data[current_index] << endl;
        return data[current_index];//<==the current index is initializing with garbage.
    }

    void Sequence::start() 
    {
        current_index = 0;
    }

    void Sequence::advance()
    {
        //current_index changes so that it returns the next item in the sequence
        current_index +=1;
    }

    bool Sequence::is_item() const 
    {
        //returns a bool to indicate whether there actually is another item for current to provide
        if (current_index > used) //<==issue for garbage initialized index here in used argument.
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void Sequence::insert(const value_type& entry)
    {   //places a new item BEFORE the current item
        size_type i;
        assert(size() < CAPACITY);
        if (used > 0)
        {
            for(i = used; i > current_index; --i)
            {
                data[i] = data[i-1];
            }
        }    
        data[current_index] = entry;
        ++used;

    }

    void Sequence::attach(const value_type& entry)
    {
        //adds a new item to the sequence AFTER the current item
        assert(size() < CAPACITY);
        cout << "THIS IS THE CURRENT INDEX BEFORE RUNNING " << current_index << endl;
        if(used > 0)
        {
            for (size_type i = used; i > current_index; --i)
            {
                data[i] = data[i - 1];
            }
            data[current_index] = entry;
            ++used;
            current_index +=1;
            cout<<"THIS IS THE CURRENT INDEX AFTER RUNNING " << current_index << " THIS IS current() " << current() << endl;
        }   
    }

    Sequence::size_type Sequence::size() const
    {
        return used;
    }

    void Sequence::remove_current()
    {
        //Library facilities used: assert
        //removes the current item from the sequence
        assert(size() > 0);
        for(size_type i = current_index + 1; i < used; i++)
        {
            data[i -1 ] = data [i];
        }
        used --;
        current_index -=1;
    }
}
