#include "Queue.h"
#include "QueueNode.h"

#include <assert.h>

Queue::Queue(){
    this->head = new QueueNode(0);
    this->tail = this->head;
    this->length = 0;
}

void Queue::enqueue(int value){
    QueueNode *new_node;
    if (this->length == 0){
        this->head->value = value;
        this->tail = this->head;
    } else {
        new_node = new QueueNode(value);
        new_node->prev = this->tail;
        new_node->prev->next = new_node;
        this->tail = new_node;
    }
    this->length++;
}

int Queue::dequeue(){
    int result;
    QueueNode *to_dequeue;

    assert(this->length > 0);
    if (this->length == 1){
        result = this->head->value;
    } else {
        result = this->head->value;
        to_dequeue = this->head;
        this->head = this->head->next;
        delete(to_dequeue);
        this->head->prev = nullptr;
    }
    this->length--;

    return result;
}

int Queue::peek(){
    assert(this->length > 0);
    return this->head->value;
}

bool Queue::is_empty(){
    return (this->length == 0);
}
