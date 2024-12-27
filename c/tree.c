#include "tree.h"
#include <stdlib.h>
#include <assert.h>

struct Node *create_node(int root_data) {
    struct Node *node = malloc(sizeof(struct Node));
    assert(node != NULL);
    node->data = root_data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insert(struct Node *root, char *loc_address, char direction, int node_data) {
    if (root == NULL) {
        return -4;
    }
    if (direction != 'L' && direction != 'R') {
        // unknown direction
        return -3;
    }
    struct Node *c = root;
    char *l = loc_address;
    while (*l != '\0') {
        if (*l == 'L') {
            c = c->left;
        } else if (*l == 'R') {
            c = c->right;
        } else {
            // unknown character
            return -2;
        }
        if (c == NULL) {
            // path not found
            return -1;
        }
        ++l;
    }
    struct Node *n = create_node(node_data);
    // left direction
    if (direction == 'L') {
        if (c->left == NULL) {
            c->left = n;
        } else {
            n->left = c->left;
            c->left = n;
        }
        return 0;
    }
    // right direction
    if (c->right == NULL) {
        c->right = n;
    } else {
        n->right = c->right;
        c->right = n;
    }
    return 0;
}
