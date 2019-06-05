#include <assert.h>

#include "DLLNode.h"
#include "DoublyLinkedList.h"

// When we initialize the DLL, we... ah, you know what?
// You can figure it out from the comments on the singlu
// linked list.
DoublyLinkedList::DoublyLinkedList(int value)
{
    this->length = 1;
    this->head = new DLLNode(value);
}

int DoublyLinkedList::get(int position){
    assert(position >= 0 && position < this->length);
    DLLNode *node = this->head;
    for (int i = 0; i < position; i++)
        node = node->next;

    return node->value;
}

void DoublyLinkedList::append(int value){
    DLLNode *node = this->head;
    while (node->next != nullptr)
        node = node->next;

    node->next = new DLLNode(value);
    node->next->prev = node;
    this->length++;
}

void DoublyLinkedList::insert(int position, int value){
    assert(position >= 0 && position <= this->length);
    DLLNode *current = this->head;
    DLLNode *new_node;

    if (position == this->length){
        this->append(value);
    } else {
        new_node = new DLLNode(value);
        for (int i = 0; i < position; i++){
            current = current->next;
        }

        new_node->prev = current->prev;
        if (new_node->prev != nullptr) new_node->prev->next = new_node;
        new_node->next = current;
        if (new_node->next != nullptr) new_node->next->prev = new_node;
    }
    this->length++;
}

void DoublyLinkedList::remove(int position){
    DLLNode *current = this->head;
    assert(position >= 0 && position < this->length);

    if (position == 0){
        this->head = current->next;
        this->head->prev = nullptr;
    } else {
        for (int i = 0; i < position; i++){
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

    }

    delete(current);
    this->length--;
}

int DoublyLinkedList::getLength(){
    return length;
}
