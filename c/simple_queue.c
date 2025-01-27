#include "simple_queue.h"
#include <stdlib.h>
#include "assert.h"

struct Queue *create_queue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    assert(queue != NULL);
    queue->first = NULL;
    return queue;
}

void destroy_queue(struct Queue *queue) {
    if (queue == NULL) {
        return;
    }
    struct Node *n = queue->first;
    while (n != NULL) {
        queue->first = queue->first->next;
        free(n);
        n = queue->first;
    }
    free(queue);
}

void enqueue(struct Queue *queue, int element) {
    struct Node *node = malloc(sizeof(struct Node));
    assert(node != NULL);
    node->data = element;
    node->next = NULL;
    if (queue->first == NULL) {
        queue->first = node;
    } else {
        node->next = queue->first;
        queue->first = node;
    }
}

int dequeue(struct Queue *queue) {
    if (queue == NULL || queue->first == NULL) {
        return -1;
    }
    int data;
    if (queue->first->next == NULL) {
        data = queue->first->data;
        free(queue->first);
        queue->first = NULL;
    } else {
        struct Node *n = queue->first->next;
        struct Node *p = queue->first;
        while (n->next != NULL) {
            p = n;
            n = n->next;
        }
        data = n->data;
        free(n);
        p->next = NULL;
    }
    return data;
}

int get_size(struct Queue *queue) {
    if (queue == NULL || queue->first == NULL) {
        return 0;
    }
    struct Node *c = queue->first;
    int k = 0;
    while (c != NULL) {
        ++k;
        c = c->next;
    }
    return k;
}

int peek(struct Queue *queue) {
    if (queue == NULL || queue->first == NULL) {
        return -1;
    }
    struct Node *c = queue->first;
    while (c->next != NULL) {
        c = c->next;
    }
    return c->data;
}
