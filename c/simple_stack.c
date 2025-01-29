#include "simple_stack.h"
#include <stdlib.h>
#include <assert.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack *create_stack() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    assert(stack != NULL);
    stack->first = NULL;
    return stack;
}

void destroy_stack(struct Stack *stack) {
    while (stack->first != NULL) {
        struct Node *n = stack->first;
        stack->first = stack->first->next;
        free(n);
    }
    free(stack);
}

void push(struct Stack *stack, int e) {
    assert(stack != NULL && "Cannot push to a NULL stack");
    struct Node *node = malloc(sizeof(struct Node));
    assert(node != NULL);
    node->data = e;
    if (stack->first == NULL) {
        node->next = NULL;
        stack->first = node;
    } else {
        node->next = stack->first;
        stack->first = node;
    }
}

int pop(struct Stack *stack) {
    assert(stack != NULL && "Cannot pop from a NULL stack");
    assert(stack->first != NULL && "Cannot pop from a NULL stack");

    struct Node *n = stack->first;
    stack->first = stack->first->next;

    int e = n->data;
    free(n);

    return e;
}

int peek(struct Stack *stack) {
    assert(stack != NULL && "Cannot peek from a NULL stack");
    assert(stack->first != NULL && "Cannot peek from a NULL stack");

    return stack->first->data;
}

bool is_empty(struct Stack *stack) {
    return stack == NULL || stack->first == NULL;
}
