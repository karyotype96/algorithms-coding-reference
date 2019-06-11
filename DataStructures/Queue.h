#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"

class Queue
{
    public:
        Queue();

        void enqueue(int value);
        int dequeue();
        int peek();

        bool is_empty();

    private:
        QueueNode *head, *tail;
        int length;
};

#endif // QUEUE_H
