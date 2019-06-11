#include "Stack.h"
#include "StackNode.h"

#include <assert.h>

Stack::Stack(){
    this->top = new StackNode(0);
    this->length = 0;
}

void Stack::push(int value){
    StackNode *new_node;
    if (this->length == 0){
        this->top->value = value;
    } else {
        new_node = new StackNode(value);
        new_node->below = this->top;
        this->top = new_node;
    }
    this->length++;
}

int Stack::pop(){
    int result;
    StackNode *to_pop;

    assert(this->length > 0);
    if (this->length == 1){
        result = this->top->value;
    } else {
        result = this->top->value;
        to_pop = this->top;
        this->top = this->top->below;
        delete(to_pop);
    }
    this->length--;

    return result;
}

int Stack::peek(){
    assert(this->length > 0);
    return this->top->value;
}

bool Stack::is_empty(){
    return (this->length == 0);
}
