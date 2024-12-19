// generic_linked_list.h
#ifndef GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_H

#include <stdlib.h>

// Public structure that users of our library need to know about
struct Node {
    int id;
    void *data;
    size_t data_size;
    struct Node *next;
};

extern struct Node *first;
void add_node(int id, void *data, size_t data_size);
void free_node(struct Node *node);
void remove_node(int id);

#endif // GENERIC_LINKED_LIST_H
