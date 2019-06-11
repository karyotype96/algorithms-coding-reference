#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

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
