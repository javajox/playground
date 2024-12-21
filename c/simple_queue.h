#ifndef C_SIMPLE_QUEUE_H
#define C_SIMPLE_QUEUE_H

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    // pointer to the first element
    struct Node *first;
};

struct Queue *create_queue();
void destroy_queue(struct Queue *queue);

void enqueue(struct Queue *queue, int element);
int dequeue(struct Queue *queue);

#endif //C_SIMPLE_QUEUE_H