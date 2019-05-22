#include <assert.h>

#include "SLLNode.h"
#include "SinglyLinkedList.h"

// When we initialize the SLL, we have to add an initial
// value right away, otherwise there's going to be
// weirdness.
SinglyLinkedList::SinglyLinkedList(int value){
    this->length = 1;
    this->head = new SLLNode(value);
}

// Gets the value of the node at the given position in
// the SLL. This is done through linear search.
int SinglyLinkedList::get(int position){
    assert(position >= 0 && position < this->length);
    SLLNode *node = this->head;
    for (int i = 0; i < position; i++)
        node = node->next;

    return node->value;
}

// Adds a value to the end of the SLL. This also has the
// effect of increasing its length by 1.
void SinglyLinkedList::append(int value){
    SLLNode *node = this->head;
    while (node->next != nullptr)
        node = node->next;

    node->next = new SLLNode(value);
    this->length++;
}

// This method of inserting a value into a linked list
// inserts the value at the index before the position.
void SinglyLinkedList::insert(int position, int value){
    assert(position >= 0 && position <= this->length);
    SLLNode *prev, *current = this->head;
    SLLNode *new_node;

    if (position == this->length){
        this->append(value);
    } else {
        new_node = new SLLNode(value);
        for (int i = 0; i < position; i++){
            prev = current;
            current = current->next;
        }

        new_node->next = current;
        prev->next = new_node;
    }
    this->length++;
}

// Gets rid of the node at the index specified. It does this
// by changing the pointer of the preceding node to point to
// the node that comes after the one we're deleting, and then
// freeing the space allocated for the node.
void SinglyLinkedList::remove(int position){
    SLLNode *prev, *current = this->head;
    assert(position >= 0 && position < this->length);

    if (position == 0){
        this->head = current->next;
    } else {
        for (int i = 0; i < position; i++){
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
    }

    delete(current);
    this->length--;
}

int SinglyLinkedList::getLength(){
    return length;
}
