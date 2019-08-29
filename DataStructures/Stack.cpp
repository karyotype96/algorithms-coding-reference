#include "Stack.h"
#include "StackNode.h"

#include <assert.h>

Stack::Stack(){
    this->top = new StackNode(0);
    this->length = 0;
}

// Whenever we add a new value to the stack, we "push"
// it to the top. The top of the list is tracked by the
// list's head. Ironically, that means we have to move
// the head back anytime we add a new node.

// Note that technically, the stack will always have a
// node in it, but the coding will treat a list with
// length 0 as an empty stack.
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

// Should be pretty self-explanatory - remove the node
// from the top of the stack and return the data that
// was in it.
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

// Returns the value on the top node on the stack,
// but doesn't pop the node.
int Stack::peek(){
    assert(this->length > 0);
    return this->top->value;
}

// Is it empty? Yes? No? Well, glad we figured that
// one out. What's for lunch?
bool Stack::is_empty(){
    return (this->length == 0);
}
