#include "simple_queue.h"
#include <stdlib.h>
#include "assert.h"

struct Queue *create_queue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    assert(queue != NULL);
    queue->first = NULL;
    queue->last = NULL;
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
    if (queue->first == NULL && queue->last == NULL) {
        queue->first = node;
        queue->last = node;
        return;
    }
    assert(queue->last != NULL);
    queue->last->next = node;
    queue->last = node;
}

int dequeue(struct Queue *queue) {
    if (queue == NULL || queue->first == NULL) {
        return -1;
    }
    int data = queue->first->data;
    struct Node *n = queue->first;
    queue->first = queue->first->next;
    free(n);
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
    return queue->first->data;
}
