#ifndef DLLNODE_H
#define DLLNODE_H


class DLLNode
{
    public:
        DLLNode(int value);

        int value;
        DLLNode *prev;
        DLLNode *next;

    protected:

    private:
};

#endif // DLLNODE_H
