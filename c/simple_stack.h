#ifndef C_SIMPLE_STACK_H
#define C_SIMPLE_STACK_H

#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    // point on the first element
    struct Node *first;
};

struct Stack *create_stack();
void destroy_stack(struct Stack *stack);

void push(struct Stack *stack, int e);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
bool is_empty(struct Stack *stack);

#endif //C_SIMPLE_STACK_H
