#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "SLLNode.h"

/*
    A singly linked list is a data structure made up of "nodes",
    each containing two things: a piece of data, and a pointer
    to the next node in the list. The data in this case is a single
    integer.

    The advantage of a SLL is that inserting a value into the list is
    very fast, with a complexity of O(1), but the downside is that
    accessing an element in the list is slow, with a complexity of
    O(n).
*/

class SinglyLinkedList
{
    public:
        SinglyLinkedList(int value);

        int get(int position);
        void append(int value);
        void insert(int position, int value);
        void remove(int position);

        int getLength();

    private:
        SLLNode *head;
        int length;
};

#endif // SINGLYLINKEDLIST_H
