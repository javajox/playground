#include "simple_queue.h"
#include <stdlib.h>
#include "assert.h"

struct Queue *create_queue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->first = NULL;
    assert(queue != NULL);
    return queue;
}

void destroy_queue(struct Queue *queue) {
    if (queue == NULL) {
        return;
    }
    struct Node *n = queue->first;
    while (queue->first != NULL) {
        queue->first = queue->first->next;
        free(n);
        n = queue->first;
    }
    free(queue);
}

struct Node *find_last(struct Queue *queue) {
    if (queue->first == NULL) {
        return NULL;
    }
    struct Node *node = queue->first;
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}

void enqueue(struct Queue *queue, int element) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = element;
    node->next = NULL;
    if (queue->first == NULL) {
        queue->first = node;
    } else {
        struct Node *last = find_last(queue);
        last->next = node;
    }
}

int dequeue(struct Queue *queue) {
    if (queue == NULL || queue->first == NULL) {
        return -1;
    }
    struct Node *n = queue->first;
    queue->first = queue->first->next;
    int data = n->data;
    free(n);
    return data;
}
