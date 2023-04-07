// FILE: node1.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <cassert> // Provides assert
#include <cstdlib> // Provides NULL and size_t

namespace NODE_1
{
    //computes the number of nodes in a linked list.
    //Since we are not going to change the list, this parameter is a const node*
    size_t list_length(const node* head_ptr) // Library facilities used: cstdlib
    {
        //Never call new unless you are actually increasing the number of nodes.
        //You might be tempted to write [cursor = new node] to try to initialize this pointer variable. Don’t!
        const node *cursor; //This is required to be const because the head_ptr parameter is const, so that if cursor was not const, then the compiler would not permit the assignment
        size_t answer;

        answer = 0;
        for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
            ++answer;
        return answer;
    }

    /*The head_ptr is a reference parameter, since the function creates a new head
    node and makes the head pointer point to this new node.*/
    //Reference parameters that are pointers to a node.
    //Inserting a New Node at the Head of a Linked List
    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
        head_ptr = new node(entry, head_ptr); //You can read this statement as saying “make head_ptr point to the newly created node.”
    }
        

    /*A node pointer should be a value parameter when the function needs access
    to the linked list, and the function might change the linked list, but the function
    does not need to make the pointer point to a new node.*/
    //functions will add a new node after a specified node in the list.
    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
        node *insert_ptr;

        insert_ptr = new node(entry, previous_ptr->link());
        previous_ptr->set_link(insert_ptr);

        /* More clear like that
        1. Allocate a new node pointed to by a local variable called insert_ptr.
        2. Place the new entry in the data field of the new node.
        3. Make the link_field of the new node point to the node after the new
        node’s location (or NULL if there are no nodes after the new location).
        4. Make previous_ptr->link_field point to the new node that we just created.
        
        node *insert_ptr;
        insert_ptr = new node;
        insert_ptr->set_data(entry);
        insert_ptr->set_link( previous_ptr->link( ) );
        previous_ptr->set_link(insert_ptr);


        //(Don’t!) delete insert_ptr: Never call delete unless you are actually reducing the number of nodes.
        */
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    {
        node *cursor;
        for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
            if (target == cursor->data())
                return cursor;
        return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    {
        const node *cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)// Library facilities used: cassert, cstdlib
    {
        node *cursor;
        size_t i;
        assert(position > 0);
        cursor = head_ptr;
        for( i = 1;(i < position) && (cursor != NULL); i++)
            cursor = cursor->link();
        return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position) 
    // Library facilities used: cassert, cstdlib
    {
        const node *cursor;
        size_t i;
        assert(position > 0);
        for(i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link();
        return cursor;
    }

    /*
    1. Set head_ptr and tail_ptr to NULL.
    2. if (source_ptr == NULL), then return with no further work.
    3. Allocate a new node for the head node of the new list that we are creating.
    Make both head_ptr and tail_ptr point to this new node, and copy
    data from the head node of the original list to our new node.
    4. Make source_ptr point to the second node of the original list, then the
    third node, then the fourth node, and so on until we have traversed all of
    the original list. At each node that source_ptr points to, add one new
    node to the tail of the new list, and move the tail pointer forward to the
    newly added node,
    */
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) // Library facilities used: cstdlib
    {
        head_ptr = tail_ptr = NULL;

        // Handle the case of the empty list.
        if (source_ptr == NULL)
            return;

        // Make the head node for the newly created list, and put data in it.
        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        source_ptr = source_ptr->link();
        while (source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->data());
            tail_ptr = tail_ptr->link();
            source_ptr = source_ptr->link();
        }  
    }

    //As with list_head_insert, the head pointer is a reference parameter, since the
    //function makes the head pointer point to a different node.
    void list_head_remove(node *& head_ptr)
    {
        node *remove_ptr;

        remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }

    //previous_ptr does not actually point to the node that we are
    //deleting (the 42); instead it points to the node that is just before the condemned
    //node. This is because the link field of the previous node must be reassigned,
    //hence we need a pointer to this previous node.
    void list_remove(node* previous_ptr)
    {
        node *remove_ptr;

        remove_ptr = previous_ptr->link();
        previous_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
        while (head_ptr !=NULL)
        {
            list_head_remove(head_ptr);
        }
    }

    //Note:
        //[the -> operator] is called the member selection operator or component selection operator. 
        //Ex: cout << head_ptr->data( );
        //to solve the () issue such as:  cout <<(*head_ptr).data( );


        //*p : Never dereference the null pointer.
}
