#include "simple_stack.h"
#include <stdlib.h>
#include <assert.h>

struct Stack *create_stack() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    assert(stack != NULL);
    stack->first = NULL;
    return stack;
}

void destroy_stack(struct Stack *stack) {
    if (stack == NULL) {
        return;
    }
    if (stack->first == NULL) {
        free(stack);
        return;
    }
    struct Node *n = stack->first;
    struct Node *p = NULL;
    while (n != NULL) {
        p = n;
        n = n->next;
        free(p);
    }
}

void push(struct Stack *stack, int e) {
    assert(stack != NULL && "Cannot push to a NULL stack");
    struct Node *node = malloc(sizeof(struct Node));
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
