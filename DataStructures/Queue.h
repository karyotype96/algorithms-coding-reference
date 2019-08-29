#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"

/*
    A queue is a FIFO data structure in which
    nodes are either "enqueued" or "dequeued".
    When a node is enqueued, it is placed on
    the "back" of the queue, and when a node is
    dequeued, it's taken off the "front".
*/
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
