#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

/*
    A stack is a LIFO data structure in which each node
    is placed "on top" of the previous one. The data
    structure has two operations: push and pop. When
    a node is pushed, it is placed on top of the other
    nodes in the stack, and when a node is popped, it's
    taken off the top of the stack.
*/
class Stack
{
    public:
        Stack();

        void push(int value);
        int pop();
        int peek();

        bool is_empty();

    private:
        StackNode *top;
        int length;
};

#endif // STACK_H
