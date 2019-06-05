#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


class DoublyLinkedList
{
    public:
        DoublyLinkedList(int value);

        int get(int position);
        void append(int value);
        void insert(int position, int value);
        void remove(int position);

        int getLength();

    private:
        DLLNode *head;
        int length;
};

#endif // DOUBLYLINKEDLIST_H
