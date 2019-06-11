#ifndef QUEUENODE_H
#define QUEUENODE_H


class QueueNode
{
    public:
        QueueNode(int value);

        int value;
        QueueNode *prev, *next;

};

#endif // QUEUENODE_H
