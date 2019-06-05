#include "DLLNode.h"

DLLNode::DLLNode(int value)
{
    this->value = value;
    this->prev = nullptr;
    this->next = nullptr;
}
