#include "QueueNode.h"

QueueNode::QueueNode(int value){
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}
