#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Node {
    int id;
    void *data;
    size_t data_size;
    struct Node *next;
};

struct Node *first;

struct Node *locate_last() {
    if (first == NULL) {
        return NULL;
    }
    struct Node *c = first;
    while (c->next != NULL) {
        c = c->next;
    }
    return c;
}

void add_node(int id, void *data, size_t data_size) {
    assert(id > 0);
    struct Node *node = malloc(sizeof(struct Node));
    assert(node != NULL);
    node->data = malloc(data_size);
    assert(node->data != NULL);
    node->id = id;
    node->data_size = data_size;
    memcpy(node->data, data, data_size);
    node->next = NULL;
    struct Node *last = locate_last();
    if (last == NULL) {
        first = node;
    } else {
        last->next = node;
    }
}

void free_node(struct Node *node) {
    if (node) {
        free(node->data);
        free(node);
    }
}